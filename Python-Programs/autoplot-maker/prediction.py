import matplotlib.pyplot as plt
import pandas as pd
from pyautogui import alert, confirm, prompt
from sklearn.linear_model import LinearRegression


def predicts(df, X, y, x_label, y_label):
    model = LinearRegression()
    model.fit(df[[X]], df[[y]])
    # ask a value to predict
    predict_value = int(
        input(
            "Please enter a value of "
            + str(x_label)
            + " to predict "
            + str(y_label)
            + " = "
        )
    )
    predict = model.predict([[predict_value]])
    print("\n")
    print("Predicted value of " + str(y_label) + " is " + str(int(predict)))
