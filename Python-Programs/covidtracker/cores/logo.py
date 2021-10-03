import subprocess as sb

try:
    from colorama import Back, Fore, Style
except Exception:
    check_install = sb.run(
        "sudo apt-get intall colorama", shell=True, capture_output=True
    )
    if check_install == 0:
        pass

import sys


class Logo:
    def logo(self):
        print(
            Fore.GREEN
            + """
                                                 
   _____           _     _   _______             _             
  / ____|         (_)   | | |__   __|           | |            
 | |     _____   ___  __| |    | |_ __ __ _  ___| | _____ _ __ 
 | |    / _ \ \ / | |/ _` |    | | '__/ _` |/ __| |/ / _ | '__|
 | |___| (_) \ V /| | (_| |    | | | | (_| | (__|   |  __| |   
  \_____\___/ \_/ |_|\__,_|    |_|_|  \__,_|\___|_|\_\___|_|   
                            
              version: 1.0.1                                 
    """
        )
