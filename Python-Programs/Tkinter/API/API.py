import json
from io import BytesIO
from tkinter import *
from tkinter import messagebox

import requests
from PIL import Image, ImageTk

root = Tk()
# root.iconbitmap("D:\\Projects\\Python\\Tkinter\\api\\github.ico")
root.title("Github User Fetcher")
root.resizable(0, 0)
API = "https://api.github.com/users/"


def get_data(name):
    global data
    try:
        api_request = requests.get(API + name)
        api = json.loads(api_request.content)

        data = {
            "user_name": api["login"],
            "full_name": api["name"],
            "image": api["avatar_url"],
            "repo_num": api["public_repos"],
            "followers": api["followers"],
            "following": api["following"],
        }
        error = None

    except Exception as e:
        data = None
        error = {"message": "Error", "error": e}
        print(e)

    if error != None:
        messagebox.showerror("Error", error["message"])
    else:
        display_data(data)


def display_data(data):
    global img

    try:
        url = data["image"]
        response = requests.get(url)
        img_data = response.content
        img = ImageTk.PhotoImage(Image.open(BytesIO(img_data)).resize((200, 200)))
        user_img = Label(root, image=img)
    except Exception as e:
        print(e)
    # img = Label(root, text=f"Image: {data['image']}")

    user_name = Label(root, text=f"Username: {data['user_name']}", width=30)
    full_name = Label(root, text=f"Fullname: {data['full_name']}", width=30)
    repo_num = Label(root, text=f"Total Repo: {data['repo_num']}", width=30)
    followers = Label(root, text=f"Followers: {data['followers']}", width=30)
    following = Label(root, text=f"Following: {data['following']}", width=30)

    user_img.grid(row=2, column=0, columnspan=3)
    user_name.grid(row=3, column=0, columnspan=3)
    full_name.grid(row=4, column=0, columnspan=3)
    repo_num.grid(row=5, column=0, columnspan=3)
    followers.grid(row=6, column=0, columnspan=3)
    following.grid(row=7, column=0, columnspan=3)


username_label = Label(root, text="Enter GitHub Username").grid(row=0, column=0)
username_entry = Entry(root, width=50)
username_entry.grid(row=0, column=1, padx=10)

Button(root, text="Submit Name", command=lambda: get_data(username_entry.get())).grid(
    row=0, column=2
)

root.mainloop()
