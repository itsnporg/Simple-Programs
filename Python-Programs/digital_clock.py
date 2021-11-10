from tkinter import *
from tkinter.ttk import *
from time import strftime
root = Tk()
root.title('Digital Clock')

def time():
    string = strftime(''' %I:%M:%S %p  
%d %b, %Y''')
    label.config(text=string)
    label.after(1000, time)

label = Label(root, font=("ds-digital",50),background = 'black',foreground='white')
label.pack(anchor='center')

time()
mainloop()
