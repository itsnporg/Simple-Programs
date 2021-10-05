"""
    Program to get horoscope for
    Yesterday, Today and Tomorrow
    of any zodiac sign
"""

import inquirer
import requests
from bs4 import BeautifulSoup

zodiac_sign = {
    "Aquarius": 1,
    "Aries": 2,
    "Cancer": 3,
    "Capricorn": 4,
    "Gemini": 5,
    "Leo": 6,
    "Libra": 7,
    "Pisces": 8,
    "Sagittarius": 9,
    "Scorpio": 10,
    "Taurus": 11,
    "Virgo": 12,
}


def horoscope(zodiac_sign: int, day: str) -> str:
    """returns the horoscope"""
    url = (
        "https://www.horoscope.com/us/horoscopes/general/"
        f"horoscope-general-daily-{day}.aspx?sign={zodiac_sign}"
    )
    soup = BeautifulSoup(requests.get(url).content, "html.parser")
    return soup.find("div", class_="main-horoscope").p.text


if __name__ == "__main__":
    questions = [
        inquirer.List(
            "sign",
            message="Choose your Zodiac ",
            choices=zodiac_sign.keys(),
        ),
        inquirer.List(
            "day", message="Choose a day ", choices=["Yesterday", "Today", "Tomorrow"]
        ),
    ]

    results = inquirer.prompt(questions)
    horoscope_text = horoscope(zodiac_sign[results["sign"]], results["day"])
    print(horoscope_text)
