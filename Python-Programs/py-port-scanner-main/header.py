#!/bin/python3

import time

if __name__ != "__main__":

    def welcome():
        print("")
        print(
            " ██████╗  ██████╗ ██████╗ ████████╗    ███████╗ ██████╗ █████╗ ███╗   ██╗███╗   ██╗███████╗██████╗"
        )
        print(
            " ██╔══██╗██╔═══██╗██╔══██╗╚══██╔══╝    ██╔════╝██╔════╝██╔══██╗████╗  ██║████╗  ██║██╔════╝██╔══██╗"
        )
        print(
            " ██████╔╝██║   ██║██████╔╝   ██║       ███████╗██║     ███████║██╔██╗ ██║██╔██╗ ██║█████╗  ██████╔╝"
        )
        print(
            " ██╔═══╝ ██║   ██║██╔══██╗   ██║       ╚════██║██║     ██╔══██║██║╚██╗██║██║╚██╗██║██╔══╝  ██╔══██╗"
        )
        print(
            " ██║     ╚██████╔╝██║  ██║   ██║       ███████║╚██████╗██║  ██║██║ ╚████║██║ ╚████║███████╗██║  ██║"
        )
        print(
            " ╚═╝      ╚═════╝ ╚═╝  ╚═╝   ╚═╝       ╚══════╝ ╚═════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝"
        )
        print("--" * 50)
        print("										Crafted by Kaji")
        print("										Twitter: @kaji0x01")

    time.sleep(1)  # set sleep timer to print title after 1 sec.
    print("--" * 50)
    welcome()
    print("--" * 50)
    current_time = time.localtime(time.time())
    start_time = time.strftime("%H:%M:%S", current_time)
    print("  " * 35, "Started scanning at ", start_time)
