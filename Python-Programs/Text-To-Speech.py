from tkinter import *

import pyttsx3

engine = pyttsx3.init()

root = Tk()
root.geometry("350x350")
root.configure(bg="ghost white")
root.title("Text to Speech")
Label(root, text="Text to Speech", font="arial 20 bold", bg="white smoke").pack()
msg = StringVar()
Label(root, text="Enter Text", font="arial 15 bold", bg="white smoke").place(x=20, y=60)
entryf = Entry(root, textvariable=msg, width="50")
entryf.place(x=20, y=100)


def tts():
    message = entryf.get()
    engine.say(message)
    engine.runAndWait()


def exit():
    root.destroy()


def reset():
    msg.set("")


Button(root, text="Play", font="arial 15 bold", command=tts, width="4").place(
    x=25, y=140
)
Button(
    root, font="arial 15 bold", text="EXIT", width="4", command=exit, bg="OrangeRed1"
).place(x=100, y=140)
Button(root, font="arial 15 bold", text="RESET", width="6", command=reset).place(
    x=175, y=140
)

root.mainloop()
