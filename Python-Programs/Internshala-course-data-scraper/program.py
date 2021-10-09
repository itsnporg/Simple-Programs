from bs4 import BeautifulSoup
import requests

data=requests.get("https://trainings.internshala.com/?utm_source=is_web_internshala-menu-dropdown1").text

soup=BeautifulSoup(data,"lxml")

div=soup.find_all("div",class_="course-block")

for i in div:
    print(i.find("h4").text+" - "+i.find("p").text)
    print()