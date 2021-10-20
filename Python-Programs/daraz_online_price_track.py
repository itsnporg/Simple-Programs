import smtplib
import time

from bs4 import BeautifulSoup
from selenium import webdriver

required_price = input("Price: ")
product_url = input("Url: ")
driver = webdriver.Chrome(executable_path="chromedriver.exe")


def product_details(required_price, product_url):

    url = str(product_url)
    driver.get(url)

    def price_tracker():
        content = driver.page_source.encode("utf-8").strip()
        soup = BeautifulSoup(content, "html.parser")
        title = soup.find(class_="pdp-product-title").get_text()
        price = soup.find(class_="pdp-product-price").get_text()
        price1 = price[4:]
        price2 = price1.replace(",", "")
        actual_price = int(price2)
        print(title)
        print(actual_price)
        if actual_price <= int(required_price):

            def sendmail():
                server = smtplib.SMTP("smtp.gmail.com", 587)
                server.ehlo()
                server.starttls()
                server.ehlo()
                server.login("shresthanishant011@gmail.com", "uoxdjpwwvldoumuj")
                subject = "Price for you product has dropped"
                body = f"title: {title} price: {actual_price}"
                msg = f"Subject:{subject} \n\n {body}"
                server.sendmail(
                    "shresthanishant011@gmail.com", "srestnishant011@gmail.com", msg
                )
                print("mail Sent")

            sendmail()
        else:
            print("Waiting For Price drop")

    price_tracker()


while True:

    product_details(required_price, product_url)
    time.sleep(10)
driver.quit()
