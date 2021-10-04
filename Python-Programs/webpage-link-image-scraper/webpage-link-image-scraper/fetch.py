import argparse

import requests
import wget
from bs4 import BeautifulSoup

commands = argparse.ArgumentParser(
    prog="A simple command line tool to fetch all links and images found in webpage"
)
commands.add_argument(
    "--url", type=str, help=" 🔗 Link to the page that should be scraped", required=True
)

commands.add_argument(
    "--getlinks",
    type=bool,
    default=False,
    required=False,
    help="🔗 scrapes and prints all href links found in url argument: True | False",
)
commands.add_argument(
    "--img",
    type=bool,
    default=False,
    required=False,
    help=" 📷 fetch all image links found in page argument: True | False",
)
commands.add_argument(
    "--download",
    type=bool,
    required=False,
    help="⬇️ Downloading Images after fetching ? Values: True | False",
    default=False,
)
commands.add_argument(
    "--o",
    type=str,
    required=False,
    default="",
    # help="save downloads in provided directory path Eg  --o C:\Users\Sachit  Default:File containing Folder",
    help="📂 Save Downloads In Inputted Directory | Default: code containing folder",
)

# parsing passed command arguments
cmds = commands.parse_args()


"""This Functions Downloading file detecting filename from direct file Urls"""


def download_images(direct_img_url):
    file_content = requests.get(direct_img_url)
    file_name = wget.detect_filename(url=direct_img_url)
    filepath = cmds.o + file_name
    print("Downloading🔃", file_name)
    open(filepath, "wb").write(file_content.content)
    print("Downloaded✔️", file_name)


class Fetch:
    def __init__(self):
        """Requests passed urls and Store Response for Further use"""
        self.url = cmds.url
        response = requests.get(f"{self.url}").text
        self.htmlcontent = BeautifulSoup(response, "html.parser")

    def pull_images(self):
        """Scrapes all Images links found in img tage"""
        dwnload = cmds.download
        anchors = self.htmlcontent.find_all("img")
        filtered_list = list(set(anchors))

        for images in filtered_list:
            print(self.url + images["src"])

        """If --download True Passed image will be downloaded"""
        if dwnload == True:
            for images in filtered_list:
                complete_url_of_file = self.url + images["src"]
                download_images(complete_url_of_file)

    def get_all_links(self):
        """Get Scrapes All links found in anchor tag"""
        anchors = self.htmlcontent.find_all("a")
        for href in anchors:
            print(href["href"])


if __name__ == "__main__":
    fetch_img_link = Fetch()
    if cmds.getlinks == True:
        fetch_img_link.get_all_links()

    elif cmds.img == True:
        fetch_img_link.pull_images()

    elif cmds.img == True and cmds.getlinks == True:
        fetch_img_link.get_all_links()
        fetch_img_link.pull_images()

    else:
        print("😩Please Use some Flags 🏳️ Such as --img ,  --getlinks ")
