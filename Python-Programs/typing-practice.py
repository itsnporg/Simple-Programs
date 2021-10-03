import time
import random

paragraphs = ["enter the texts here",
              "seperated by commas",
              "yes like that"]

text = paragraphs[random.randint(0, len(paragraphs)-1)]
print(text)
points = 0
input("press 's' to start")
t1 = time.time()
user = input()
t2 = time.time()  # to calculate time between input
for i in range(len(text)):
    try:
        if user[i] == text[i]:
            points += 1
        else:
            points -= 1  # for negative marking
    except:
        pass


Accuracy = round(points/len(text)*100, 3)
Time = round(t2-t1, 2)
print(f"Accuracy = {Accuracy}\nTime = {Time} seconds ")

