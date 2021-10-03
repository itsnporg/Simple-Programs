import subprocess as sb

from cores.indentify import Identify
from cores.logo import Logo

try:
    import os
    import sys
    import time
    from time import sleep

    from colorama import Back, Fore, Style
except ModuleNotFoundError:
    check_install = sb.run(
        "sudo apt-get install colorama", shell=True, capture_output=True
    )
    if check_install.returncode == 0:
        pass

    else:
        sb.run("clear", shell=True)
        print("Error occured while installing colorama...please try again")
        exit()


class MyException(Exception):
    def __init__(self):
        self.error_msg = f"Something went wrong"


def file():
    sb.run("clear", shell=True, capture_output=True)

    def popup_message():
        sb.run("clear", shell=True)
        try:
            message = "In this difficult times please wear mask and stay healty 😷 \n "
            for letter in message:
                sleep(0.1)  # In seconds
                sys.stdout.write(Fore.YELLOW + letter)
                sys.stdout.flush()
        except KeyboardInterrupt:
            print(f"{Fore.RED} Okay Quitting!")
            exit()
        time.sleep(3)
        print(Fore.GREEN + "Please wait while running daemon")
        time.sleep(2)

    popup_message()
    os.system("clear")
    banner = Logo()
    banner.logo()
    time.sleep(2)
    identify = Identify()
    final_stats_data = []
    stats_results = identify.covid_stats()

    for stats_number in next(stats_results):
        final_stats_data.append(stats_number)

    json_data = identify.raw_data()  # Getting country and IP

    print(
        f"""
Your IP: {(json_data['ip'])}
Country: {(json_data["country_name"])}

"""
    )
    front_words = [
        "Cases",
        "Today Cases",
        "Deaths",
        "Today Deaths",
        "Recovered",
        "Tests",
        "Active",
    ]
    for i in range(7):
        print(
            f"{Style.BRIGHT}{Fore.BLUE}[+] {Fore.RED}{Style.BRIGHT} {front_words[i]}: {Style.BRIGHT}{Fore.WHITE+str(final_stats_data[i])}\n"
        )


if __name__ == "__main__":
    file()
