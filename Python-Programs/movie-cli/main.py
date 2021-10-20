import subprocess
import sys
import time

from colorama import Fore
from requests_html import HTMLSession

session = HTMLSession()
# colorama.init()
red = Fore.RED
green = Fore.GREEN
lightBlue = Fore.LIGHTBLUE_EX
lightCyan = Fore.LIGHTCYAN_EX
yellow = Fore.YELLOW
white = Fore.WHITE
magenta = Fore.MAGENTA


def banner():
    print(
        f"""\{magenta}

███╗░░░███╗░█████╗░██╗░░░██╗██╗███████╗░░░░░░░█████╗░██╗░░░░░██╗
████╗░████║██╔══██╗██║░░░██║██║██╔════╝░░░░░░██╔══██╗██║░░░░░██║
██╔████╔██║██║░░██║╚██╗░██╔╝██║█████╗░░█████╗██║░░╚═╝██║░░░░░██║
██║╚██╔╝██║██║░░██║░╚████╔╝░██║██╔══╝░░╚════╝██║░░██╗██║░░░░░██║
██║░╚═╝░██║╚█████╔╝░░╚██╔╝░░██║███████╗░░░░░░╚█████╔╝███████╗██║
╚═╝░░░░░╚═╝░╚════╝░░░░╚═╝░░░╚═╝╚══════╝░░░░░░░╚════╝░╚══════╝╚═╝"""
    )
    print()
    print()
    print(f"{green}\t\t\t\t\t developed by: bishalbagale{white}")
    print()


def main():
    currentPage = 1
    category = input(f"Enter your prefered category (series/movie)[s/m]: ")
    if category.upper() == "S":
        category = "TV"
    elif category.upper() == "M":
        category = "Movies"
    else:
        print(f"{green}Please select s or m{white}")
        main()

    searchParam = input("search : ")
    try:
        scraper(category, searchParam, currentPage)
    except:
        pass


def nextpageLink(rawLinks):
    for each in rawLinks:
        if "/torrent" in each:
            return each
    else:
        pass


def scraper(category, searchParam, currentPage):
    count = 0  # initial no. of search results
    searchParam = searchParam.replace(" ", "%20")
    url = (
        f"https://www.1377x.to/category-search/{searchParam}/{category}/{currentPage}/"
    )
    r = session.get(url)

    # get the link to the next page from search results
    tbody = r.html.find(
        "tbody", first=True
    )  # get the tablebody containing search result
    searchResults = tbody.find("tr")  # list of search results //contents of the table
    resultDict = {}  # dictionary of link to next page
    if len(searchResults) != 0:  # validate the result

        for result in searchResults:
            count += 1

            seeds = result.find(".seeds", first=True).text
            leeches = result.find(".leeches", first=True).text
            size = result.find(".size", first=True).text
            name = result.find(".name", first=True).text
            nextpage = nextpageLink(result.absolute_links)
            resultDict[count] = nextpage  # add to the dictionary
            # alter the color of output
            if count % 2 == 0:
                color = lightBlue
            else:
                color = lightCyan
            print(
                f"{color}{count}) {name} -->se:{seeds} -->le:{leeches} -->size:{size}"
            )
        try:  # check if multiple page results are available

            page = (
                r.html.find(".pagination", first=True)
                .find("ul", first=True)
                .find("li")[-1]
                .text
            )  # total no of pages
            print()
            print(f"\t\t\t\t\t\t\t{yellow}page : {currentPage}/{page}{white}")
            print(
                f"{green}\n# press p to change page or press the indexed no. to choose the content and press enter{white}"
            )
            chooseContent(resultDict, category, searchParam)
        except AttributeError:
            # In case of single page result

            print(f"\t\t\t\t\t\t\t{yellow}page : 1/1")
            chooseContent(resultDict, category, searchParam)
    else:  # in case of no valid result found
        print(f"{red}No match found !!\n check your spelling and try again later !")
        exit()


# choose the content from the results page
def chooseContent(resultDict, category, searchParam):

    indexInput = input(">> ")
    if indexInput.upper() == "P":
        moreResults(category, searchParam)
    else:
        try:
            mLink = resultDict[int(indexInput)]
            contentChoosed(mLink)
        except KeyError:  # in case of wrong index no.

            print(f"{red}Invalid input !! Enter valid input{white}")
            chooseContent(resultDict)  # go back to choosing content


def moreResults(category, searchParam):  # change page no. / view more results
    pg = input("goto page-no. : ")
    scraper(
        category,
        searchParam,
        pg,
    )


def contentChoosed(mLink):  # Scrape the torrent link of the content
    r = session.get(mLink)
    links = r.html.absolute_links
    for link in links:
        if "magnet:?" in link:
            torrentLink = link
    play(torrentLink)


def streamingMedium():  # choose streaming medium vlc/mpv

    medium = input("want to stream through vlc or mpv [v/m]? ")
    if medium.upper() == "V":
        return "vlc"  # stream through vlc
    elif medium.upper() == "M":
        return "mpv"  # stream through mpv
    else:
        print(f"\n {red}invalid input !{white}")
        streamingMedium()


def play(torrentLink):  # play the torrentlink

    cmd = []
    cmd.append("webtorrent")
    # checck download or stream option
    verify_download = input("want to stream or download [s/d]? ")
    if verify_download.upper() == "D":  # download
        cmd.append(f'"{torrentLink}"')
    elif verify_download.upper() == "S":  # stream
        medium = streamingMedium()
        cmd.append(f'"{torrentLink}"')
        if medium == "vlc":
            cmd.append("--vlc")
        else:
            cmd.append("--mpv")

    else:
        # In case of wrong option choosed (stream/download)
        print(f"\n {red}invalid input !{white}")
        play(torrentLink)

    if sys.platform.startswith("win32"):  # for windows
        subprocess.call(cmd, shell=True)
    elif sys.platform.startswith("linux") or sys.platform.startswith(
        "darwin"
    ):  # for linux and osx
        subprocess.call(cmd)


# calling
banner()
time.sleep(0.5)
main()
