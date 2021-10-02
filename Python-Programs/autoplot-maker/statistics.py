import matplotlib.pyplot as plt
import pandas as pd
from pyautogui import confirm, prompt


def math(df, y):
    print(
        """ Please select a number from list:
    1) Standard Deviation \t 2) Mean
    3) Variance           \t4) Median
    5) Mode               \t6) Range
    7) Quartile1          \t8) Quartile3
                   9) All
    """
    )
    print("\n")
    me = input("Please enter a number: ")
    if me == "1":
        # standard deviation
        std = df[y].std()
        print("Standard deviation of the data is " + str(std))
    if me == "2":
        # mean
        mean = df[y].mean()
        print("Mean of the data is " + str(mean))
    if me == "3":
        # variance
        var = df[y].var()
        print("Variance of the data is " + str(var))
    if me == "4":
        # median
        median = df[y].median()
        print("Median of the data is " + str(median))
    if me == "5":
        # mode
        mode = df[y].mode()
        print("Mode of the data is " + str(mode))
    if me == "6":
        # range
        range = df[y].max() - df[y].min()
        print("Range of the data is " + str(range))
    if me == "7":
        # quartile1
        q1 = df[y].quantile(0.25)
        print("Quartile1 of the data is " + str(q1))
    if me == "8":
        # quartile3
        q3 = df[y].quantile(0.75)
        print("Quartile3 of the data is " + str(q3))
    if me == "9":
        # all
        print(
            """
        Standard deviation of the data is {} \n
        Mean of the data is {} \n
        Variance of the data is {} \n
        Median of the data is {} \n
        Mode of the data is {} \n
        Range of the data is {} \n
        Quartile1 of the data is {} \n
        Quartile3 of the data is {} \n
        """.format(
                df[y].std(),
                df[y].mean(),
                df[y].var(),
                df[y].median(),
                df[y].mode(),
                df[y].max() - df[y].min(),
                df[y].quantile(0.25),
                df[y].quantile(0.75),
            )
        )
