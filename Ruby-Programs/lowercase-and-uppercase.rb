
# input the string
puts "Enter the string"
str=gets.chomp

#ask for the option 
puts "Choose the option: a)to lowercase b)to uppercase"
choice=gets.chomp

# condition to execute code based on the user's choice
if(choice=="a")
	i=0
	while(i!=str.size)
	    k=str[i].to_s
	    if(k>='A' and k<='Z')
	        str[i]=(k.ord+32).chr
        else
            str[i]=k
        end
	    i+=1
	end
	puts "The lowercase is #{str}"
else
	i=0
	while(i!=str.size)
	    k=str[i].to_s
	    if(k>='a' and k<='z')
	        str[i]=(k.ord-32).chr
	    else
	        str[i]=k;
	    end
	    i+=1
	end
	puts "The uppercase is #{str}"
end
