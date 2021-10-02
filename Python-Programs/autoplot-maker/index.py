import os
import statistics
import sys
import time

import find_file
import plot
import prediction

print("\n")
print("Checking If packages are installed or not")
try:
    import matplotlib

    matplotlib.use("TKAgg")
    import matplotlib.pyplot as plt
    import pandas as pd
    from pyautogui import alert, confirm, prompt
except ImportError:

    packages_ask = input(
        """Packages Not Found.
    Would you like to install them? (y/n)"""
    )

    if packages_ask == "y":
        # PACKAGES INSTALLATION PROCESS BEGIN
        # installing pip
        print("\n")
        print("Checking if pip is installed or not")
        os.system("python -m pip install --upgrade pip")
        print("Installing packages .......")
        print(
            """ __  __    _  _____ ____  _     ___ _____ _     ___ ____  
|  \/  |  / \|_   _|  _ \| |   / _ \_   _| |   |_ _| __ ) 
| |\/| | / _ \ | | | |_) | |  | | | || | | |    | ||  _ \ 
| |  | |/ ___ \| | |  __/| |__| |_| || | | |___ | || |_) |
|_|  |_/_/   \_\_| |_|   |_____\___/ |_| |_____|___|____/ 
                                                          
"""
        )
        os.system("pip install  matplotlib")
        print("matplotlib installed")
        print(
            """
         ____   _    _   _ ____    _    ____  
|  _ \ / \  | \ | |  _ \  / \  / ___| 
| |_) / _ \ |  \| | | | |/ _ \ \___ \ 
|  __/ ___ \| |\  | |_| / ___ \ ___) |
|_| /_/   \_\_| \_|____/_/   \_\____/ 
                                      

        """
        )
        os.system("pip install pandas")
        print("pandas installed")
        print(
            """ ______   __ _   _   _ _____ ___   ____ _   _ ___ 
|  _ \ \ / // \ | | | |_   _/ _ \ / ___| | | |_ _|
| |_) \ V // _ \| | | | | || | | | |  _| | | || | 
|  __/ | |/ ___ \ |_| | | || |_| | |_| | |_| || | 
|_|    |_/_/   \_\___/  |_| \___/ \____|\___/|___|
                                                  
"""
        )
        os.system("pip install pyautogui")
        print("pyautogui installed")
        print(
            """
         ____  _  ___     _____    _    ____  _   _ 
/ ___|| |/ / |   | ____|  / \  |  _ \| \ | |
\___ \| ' /| |   |  _|   / _ \ | |_) |  \| |
 ___) | . \| |___| |___ / ___ \|  _ <| |\  |
|____/|_|\_\_____|_____/_/   \_\_| \_\_| \_|
                                            
        """
        )
        os.system("pip install sklearn")
        print("sklearn installed")
        print("Packages installed :)")
        # PACKAGES INSTALLAYTION PROCESS END
        # RE-CHECKING IF PACKAGES ARE INSTALLED OR NOT
        print("Checking If packages are installed or not")
        try:
            import matplotlib

            matplotlib.use("TKAgg")
            import matplotlib.pyplot as plt
            import pandas as pd
            from pyautogui import alert, confirm, prompt
        # IF ERROR IS RAISED, THEN RE-CHECK PACKAGES
        except ImportError:
            print(
                "Sorry some error  occured while installing Packages \n Try installing manually"
            )
            print("Exiting")
            exit()
    # IF ANSWER IS NO THEN EXIT
    else:
        print(
            "IF YOU WANT TO RUN THE PROGRAM \n YOU SHOULD HAVE PACKAGES INSTALLED PLEASE RELAUNCH THIS PROGRAM TO INSTALL PACKAGES OR INSTALL IT MANUALLY"
        )
        exit()
# clear screen
def clear_screen():
    os.system("cls" if os.name == "nt" else "clear")
    # clear screen


clear_screen()
# start
print("Welcome To ")
print("\n")
print("\n")
print(
    """     _         _          ____  _       _     __  __       _             
   / \  _   _| |_ ___   |  _ \| | ___ | |_  |  \/  | __ _| | _____ _ __ 
  / _ \| | | | __/ _ \  | |_) | |/ _ \| __| | |\/| |/ _` | |/ / _ \ '__|
 / ___ \ |_| | || (_) | |  __/| | (_) | |_  | |  | | (_| |   <  __/ |   
/_/   \_\__,_|\__\___/  |_|   |_|\___/ \__| |_|  |_|\__,_|_|\_\___|_|   
                                                                        
    _              _   ____               _ _      _             
   / \   _ __   __| | |  _ \ _ __ ___  __| (_) ___| |_ ___  _ __ 
  / _ \ | '_ \ / _` | | |_) | '__/ _ \/ _` | |/ __| __/ _ \| '__|
 / ___ \| | | | (_| | |  __/| | |  __/ (_| | | (__| || (_) | |   
/_/   \_\_| |_|\__,_| |_|   |_|  \___|\__,_|_|\___|\__\___/|_|   

                 Developed By: Binayak Jha 

(note: still in development you can also contribute in this project by adding new features and giving your feedback)
"""
)

print("Starting .....")
print("\n")

data_input = input(
    "Please keep your csv file name (include .csv) here (note: do not give a path or anything else we will find the file itself :) = "
)
print("Searching Please wait ....")

# print(find_files("canada_predicted_csv.csv","/")[0])
a = find_file.find_files(data_input, "/")[0]
print("\n")
print("FILE FOUND !!")
print("\n")

print(a)
print("\n")
# asking values start
X = input("[?] please enter the data table heading which you want to show in x axis = ")
print("X = " + str(X))
print("\n")
y = input("[?] please enter the data table heading which you want to show in y axis = ")
print("Y = " + str(y))
print("\n")
x_label = str(
    input("[?] please enter the data table heading which you want to show in x axis = ")
)
print("X label = " + str(x_label))
print("\n")
y_label = str(
    input(
        "[?] please enter the data table heading which you want to show in y axis  = "
    )
)
print("Y label = " + str(y_label))
print("\n")
heading = str(
    input("[?] please enter the data table heading which you want to show in graph = ")
)
print("Heading = " + str(heading))
print("\n")
# asking values end
plt.title(heading)
df = pd.read_csv(a)
# Plot Module
plot.plot(df, X, y, x_label, y_label, heading)
# Plot Module END
print("\n")
print("\n")
print("\n")
print(
    """
 __  __    _  _____ _   _ ____  
|  \/  |  / \|_   _| | | / ___| 
| |\/| | / _ \ | | | |_| \___ \ 
| |  | |/ ___ \| | |  _  |___) |
|_|  |_/_/   \_\_| |_| |_|____/ 

"""
)
print("\n")

ask = str(input(" Do you want to see mean and other things? (y/n) "))
if ask == "y" or ask == "Y" or ask == "yes" or ask == "Yes":
    statistics.math(df, y)
    print
elif ask == "n" or ask == "N" or ask == "no" or ask == "No":
    pass

# PREDICTION
print("\n")
print(
    """
 ____  ____  _____ ____ ___ ____ _____ ___ ___  _   _ 
|  _ \|  _ \| ____|  _ \_ _/ ___|_   _|_ _/ _ \| \ | |
| |_) | |_) |  _| | | | | | |     | |  | | | | |  \| |
|  __/|  _ <| |___| |_| | | |___  | |  | | |_| | |\  |
|_|   |_| \_\_____|____/___\____| |_| |___\___/|_| \_|
                                                      

"""
)
print("\n")
predict_ask = input("Do you want to predict? (y/n) ")
if (
    predict_ask == "y"
    or predict_ask == "Y"
    or predict_ask == "yes"
    or predict_ask == "Yes"
):
    prediction.predicts(df, X, y, x_label, y_label)
elif (
    predict_ask == "n"
    or predict_ask == "N"
    or predict_ask == "no"
    or predict_ask == "No"
):
    print("Thank you for using this program")
    print("\n")

print("Graph ....")
print(
    """
 _____ _   _ ____  
| ____| \ | |  _ \ 
|  _| |  \| | | | |
| |___| |\  | |_| |
|_____|_| \_|____/ 
                   

"""
)
print("\n")
