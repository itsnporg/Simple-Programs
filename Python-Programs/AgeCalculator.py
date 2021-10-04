from datetime import date
from tkinter import *

# Initializing tkinter
root = Tk()

# Specifying height, width & title for GUI
root.geometry("300x300")
root.title("Age Calculator")


def calculateAge():
    cur_date = date.today()
    user_dob = date(int(yearEntry.get()), int(monthEntry.get()), int(dayEntry.get()))
    age = (
        cur_date.year
        - user_dob.year
        - ((cur_date.month, cur_date.day) < (user_dob.month, user_dob.day))
    )
    Label(text=f"{userName.get()}, Your present age is {age}").grid(
        row=12, column=0, padx=10
    )


# Labels
Label(text="Name").grid(row=1, column=0, padx=30)
Label(text="Day").grid(row=2, column=0)
Label(text="Month").grid(row=3, column=0)
Label(text="Year").grid(row=4, column=0)

userName = StringVar()
year = IntVar()
month = IntVar()
day = IntVar()

# Entries
nameEntry = Entry(root, textvariable=userName)
dayEntry = Entry(root, textvariable=day)
monthEntry = Entry(root, textvariable=month)
yearEntry = Entry(root, textvariable=year)

# Aligning Entry Widgets
nameEntry.grid(row=1, column=1, pady=10)
dayEntry.grid(row=2, column=1, pady=10)
monthEntry.grid(row=3, column=1, pady=10)
yearEntry.grid(row=4, column=1, pady=10)

Button(text="Calculate age", command=calculateAge, cursor="hand2").grid(
    row=10, column=1, padx=20, pady=10
)
root.mainloop()
