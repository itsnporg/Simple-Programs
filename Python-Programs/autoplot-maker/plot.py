import matplotlib.pyplot as plt
import pandas as pd
from pyautogui import alert, confirm, prompt


def plot(df, X, y, x_label, y_label, heading):
    print("\n")
    print(
        """Please enter the type of graph you want to show:
    1) Plot      \t 2) Scatter plot
    3) Histogram \t 4) Boxplot
    5) Pie chart \t 6) Bar chart
    7) Area plot \t 8) Line plot 
    """
    )
    print("\n")
    type_graph = input("Enter the number = ")
    if type_graph == "1":
        # want to add a marker in your plot?
        marker = input("Do you want to add a marker in your plot? (y/n)")
        if marker == "y" or marker == "Y" or marker == "yes" or marker == "Yes":
            marker_input = input("Please enter the marker you want to add eg(*,^) = ")
            plt.plot(df[X], df[y], marker=marker_input)
        else:
            plt.plot(df[X], df[y])
        plt.xlabel(x_label)
        plt.ylabel(y_label)

    elif type_graph == "1":
        plt.scatter(df[X], df[y])
        plt.xlabel(x_label)
        plt.ylabel(y_label)
    elif type_graph == "2":
        plt.scatter(df[X], df[y])
        plt.xlabel(x_label)
        plt.ylabel(y_label)
    elif type_graph == "3":
        plt.hist(df[y])
        plt.xlabel(x_label)
        plt.ylabel(y_label)

    elif type_graph == "4":
        plt.boxplot(df[y])
        plt.xlabel(x_label)
        plt.ylabel(y_label)

    elif type_graph == "5":
        plt.pie(df[y], labels=df[X])

    elif type_graph == "6":
        # fwhat bar graph horizontally or vertically
        print(
            """Do you want to show bar graph horizontally or vertically?
    \t 1) Horizontal
    \t 2) Vertical  """
        )
        ask2 = input("Enter the number: ")
        if ask2 == "1":
            plt.barh(df[X], df[y])
            plt.xlabel(x_label)
            plt.ylabel(y_label)
        elif ask2 == "2":
            plt.bar(df[X], df[y])
            plt.xlabel(x_label)
            plt.ylabel(y_label)

    elif type_graph == "7":
        plt.plot(df[X], df[y])
        plt.xlabel(x_label)
        plt.ylabel(y_label)
    # after seeing the graph close it to continue
    save_fig = input("Do you want to save the graph? (y/n) = ")
    if save_fig == "y" or save_fig == "Y" or save_fig == "yes" or save_fig == "Yes":
        plt.savefig(input("Please enter the file name  eg (abc.png or abc.jpg) = "))
        print("Picture saved  in the same folder where I am !! ")
    print("Here is the graph  .....")
    plt.show()
