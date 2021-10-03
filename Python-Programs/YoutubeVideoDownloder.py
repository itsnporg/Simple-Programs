# Aurthor:- Leyuskc
# Simple and easy youtube vide downloader
# Follow me for such simple ideas

try:
    import itertools
    import time
    import uuid
    from threading import Thread
    from urllib.parse import unquote

    import requests
except Exception as e:
    print("Error:- \n\t[+]", e)
    if input("Do you want me to install the missing requests libary").casefold() == "y":
        import os

        os.system("python -m pip install requests")
    else:
        exit(0)

query = input(" Enter your URL   ")
timer = time.time()
res = requests.get(
    query,
    headers={
        "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.85 Safari/537.36"
    },
)
a = res.content
try:
    b = a.decode().split(
        '"formats":[{"itag":18,"url":"'
    )  # using simple text analysis rather then import havey modules like bs4 for work load
    c = b[1].split('","mimeType":"video/mp4;')[0]
    # unquote(c)
    url = eval(
        f"unquote('{c}')"
    )  # for adding more threads print this url and you can see bytes=1455-s5454 some thing like this and        #                           maupulate the thread range accoring to the thread for more faster experiecnce
    finished = False
except:
    print(
        "This video requires age confirmation so that's why please login by yourself can't be downloded, Or You can try our premium version which bypases then age confirmation. "
    )
    exit()


def download(url):
    global finished
    video = requests.get(
        url,
        headers={
            "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.85 Safari/537.36"
        },
    )
    name = uuid.uuid1()
    with open(f"{name}.mp4", "wb") as opn:
        opn.write(video.content)
    finished = True


def loader():
    global finished
    for i in itertools.cycle(
        [
            "\\",
            "-",
            "/",
            "|",
        ]
    ):
        if finished:
            break
        print(f"\rDownloading {i}", end="")


t1 = Thread(
    target=download, args=(url,)
)  # You can also use thread pools of you want to if you are going to download many video at once
t2 = Thread(target=loader)

t1.start()
t2.start()
t1.join()
t2.join()

print("############# Downloded ##############")
print(f"It took {time.time()-timer} sec")

# At 50mb/s it's max speed is (1min video)/sec
# which means 1hrs video will be downloded in 60 sec in 50mb/s or you can add some extra Threads and distrubute the bytes('I will mark #above') and run 4 -10 threads wnd it will get more faster if video is really long but for short video It doesn't matter.
