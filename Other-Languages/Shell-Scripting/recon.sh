#!/bin/bash

# Recon automation script that finds all the subdomains of the given domain, manages your scans and uses eyewitness to capture screenshots.
# used tools: subfinder, httprobe, eyewitness, nmap
# developed by b0s0 long time ago

if [ $# -lt 2 ]; then
	echo "Usage: ./recon.sh <direcrtory_name> <domain1>...<domain n>"
	echo "Example: ./recon.sh tesla_recon tesla.com"
	exit 1
fi

echo "Initiating ....."
dir=$1

mkdir $dir 
cd $dir

for i in $(seq 2 $#);
do echo ${!i} >> domains.txt
done

echo "Gathering subdomains using subfinder..."
subfinder -dL domains.txt -o final.txt
cat domains.txt >> ./final.txt

echo "Managing stuff.."
cat final.txt | grep -Po "(\w+\.\w+\.\w+)$" | sort -u >> subdomains.txt


echo "Any out of scope subdomain ? y/n"
read ans
if [ ${ans,,} == 'y' ]; then
        echo "How many?"
        read num
        for nu in $(seq 1 $num);
        do 
                echo "Enter the subdomain that is out of scope"
                read out_sub_dom
                sed -i "/\<\$out_sub_dom\>/d" subdomains.txt
		sed -i "/.\<\$out_sub_dom\>/d" subdomains.txt
		sed -i "/\<\$out_sub_dom\>/d" final.txt
		sed -i "/.\<\$out_sub_dom\>/d" final.txt
        done  
fi


echo "Any subdomains that cannot be further enumerated to find fourth level domains? y/n"
read answer
if [ ${answer,,} == 'y' ]; then
	echo "How many?"
	read number
	for n in $(seq 1 $number);
	do 
		echo "Enter the subdomain you want to exclude"
		read sub_dom
		sed -i "/\<$sub_dom\>/d" subdomains.txt
		sed -i "/.\<$sub_dom\>d" subdomains.txt
	done
fi

echo "Gathering full subdomains with subfinder..."
mkdir subdomains
for domain in $(cat subdomains.txt);
do
	subfinder -d $domain -o subdomains/$domain.txt; cat subdomains/$domain.txt | sort -u >> final.txt;
done

echo "Probing for alive subdomains.."
cat final.txt | sort -u | httprobe -s -p https:443 | sed 's/https\?:\/\///' | tr -d ":443" > probed.txt

mkdir scans
echo "thx for using recon.sh . nmap and eyewitness will begin soon"
nmap -iL probed.txt -sC -sV -oA scans/nmap.txt;
eyewitness -f probed.txt -d $1 --all-protocols 
