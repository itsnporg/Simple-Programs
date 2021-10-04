import requests as rq
import os
import pandas as pd
import json
from colorama import Fore,Style,Back,init
from bs4 import BeautifulSoup
import time

to_nepse=f"http://www.nepalstock.com/main/todays_price/index/"

init(autoreset=True)


titles=[]
SN=[]
traded_comp=[]
no_of_trans=[]
max_price=[]
min_price=[]
closing_price=[]
traded_shares=[]
amount=[]
prev_closing=[]
difference=[]  



def pd_columns() -> list:

    for firstpage in range(1):
        res=rq.get(f"{to_nepse}{firstpage+1}").text
        souped_data=BeautifulSoup(res,'html5lib')
        main_table=souped_data.findAll('table',attrs={'class':'table table-condensed table-hover'})[0]
        #print(main_table)
        for tds in main_table.find_all('tr',{'class':'unique'}):
            for td in (tds.find_all("td")):
                titles.append(td.getText())
                #print(td.getText())
    headers=list(filter(lambda x: x!="S.N.",titles))
    return headers


def scrap():

    with open('metadata.json','r') as metadata:
        jsondata=json.loads(metadata.read())
    name=jsondata["name"]
    author=jsondata["author"]
    discord=jsondata["discord"]
    infos=[name,author,discord]
    count=0
    for cred in jsondata:
        print(f'{Style.BRIGHT}{cred}: {Fore.YELLOW}{infos[count]}{Fore.RESET}')
        count+=1
    time.sleep(1)
    for page_indexing in range(12):
        to_skip=0
        vals=[]
        res=rq.get(f'{to_nepse}{page_indexing+1}').content.decode('utf-8')
        souped_data=BeautifulSoup(res,'html.parser')
        main_table=souped_data.find_all('table',{'class':'table table-condensed table-hover'})[0]
        for trs in main_table.find_all('tr'):
            if to_skip<2:
                to_skip+=1
                continue
            else:
                try:
                    vals=trs.find_all('td')
                    #SN.append(vals[0].getText())
                    traded_comp.append(vals[1].getText())
                    print(f'{Fore.GREEN}{Style.BRIGHT}[-]  {Fore.WHITE}{Style.BRIGHT}{vals[1].getText()}')
                    no_of_trans.append(vals[2].getText())
                    max_price.append(vals[3].getText())
                    min_price.append(vals[4].getText())
                    closing_price.append(vals[5].getText())
                    traded_shares.append(vals[6].getText())
                    amount.append(vals[7].getText())
                    prev_closing.append(vals[8].getText())
                    difference.append(vals[9].getText())
                except IndexError:
                    break

def createCSV(file_name:str):

    titles=pd_columns()
    df=pd.DataFrame(columns=titles)
    df["Traded Companies"]=traded_comp
    df["No. Of Transaction"]=no_of_trans
    df["Max Price"]=max_price
    df["Min Price"]=min_price
    df["Closing Price"]=closing_price
    df["Traded Shares"]=traded_shares
    df["Amount"]=amount
    df["Previous Closing"]=prev_closing
    df["Difference Rs."]=difference
    decode_unicode=df['Difference Rs.'].str.split().str.join(' ')
    df["Difference Rs."]=decode_unicode
    df.drop(df.filter(regex="Unname"),axis=1, inplace=True)
    df.to_csv(f"{file_name}.csv",index=False)
    print(f" saved your file under {Fore.RED}{Style.BRIGHT}{file_name}.csv ")


if  __name__=="__main__":

    scrap()
    yes_or_no=input("Do you want to save your file (y/n):  ")
    
    if yes_or_no.lower()=="y":
        file_name=input("Enter your file name: ")
        createCSV(file_name)
           
    else:
        print("Okay exiting...")
        exit()

