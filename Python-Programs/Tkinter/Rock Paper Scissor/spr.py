import random
from tkinter import *

root = Tk()
root.resizable(0, 0)
root.title("Rock Paper Scissor")
root.iconbitmap("D:\\Projects\\Python\\Tkinter\\sci_pap_rock\\cut.ico")
choices = ["Scissor", "Paper", "Rock"]


def parse_result(status):
    if status == 1:
        return "Draw"
    elif status == 2:
        return "You Win! :D"
    elif status == 0:
        return "You Loose! :("


def get_bg_color(status):
    if status == 1:
        return "yellow"
    elif status == 2:
        return "lightgreen"
    elif status == 0:
        return "#fc685d"


def handle_input(status):

    frame = LabelFrame(padx=10, pady=10).grid(row=5, column=0)
    computer = comp_turn()
    result = checkResult(status, computer)
    result_status = parse_result(result)

    color_value = get_bg_color(result)
    root.configure(bg=color_value)
    Label(
        frame, background=color_value, width=20, text=f"You Chose: {choices[status]}"
    ).grid(row=6, column=0, columnspan=3)
    Label(
        frame,
        background=color_value,
        width=20,
        text=f"Computer Chose: {choices[computer]}",
    ).grid(row=7, column=0, columnspan=3)
    Label(frame, background=color_value, width=20, text=result_status).grid(
        row=8, column=0, columnspan=3
    )
    return


def checkResult(user, computer):
    if user == computer:
        return 1
    elif (
        (user == 0 and computer == 1)
        or (user == 1 and computer == 2)
        or (user == 2 and computer == 0)
    ):
        return 2
    return 0


def comp_turn():
    return random.randint(0, 2)


sci_btn = Button(root, text="Scissor", command=lambda: handle_input(0)).grid(
    row=0, column=0
)
pap_btn = Button(root, text="Paper", command=lambda: handle_input(1)).grid(
    row=0, column=1
)
rock_btn = Button(root, text="Rock", command=lambda: handle_input(2)).grid(
    row=0, column=2
)

root.mainloop()
