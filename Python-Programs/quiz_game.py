import html
from random import shuffle

import requests

url = r"https://opentdb.com/api.php?type=multiple&amount="
score = 0
# Ask user for number of questions
while True:
    try:
        num_questions = int(input("Number of questions : "))
        if num_questions < 1 or num_questions > 50:
            print("Please enter a number between 1 and 50.")
        else:
            break
    except:
        print("Please enter a valid number between 1 and 50.")

# Ask user for difficulty
difficulty = input("Difficulty [easy|medium (default)|hard] : ")

diff = (
    "medium"
    if difficulty.lower() not in ["easy", "medium", "hard"]
    else difficulty.lower()
)

if difficulty.lower() not in ["easy", "medium", "hard"]:
    print("Quiz setup :")
    print(f" - {num_questions} questions")
    print(f" - {diff.capitalize()} difficulty")


url += str(num_questions) + "&difficulty=" + diff

req = requests.get(url)

for i in range(num_questions):
    item = req.json()["results"][i]
    question = html.unescape(item["question"])

    print(f"Question {i+1} : {question}")

    correct = [item["correct_answer"]]
    wrongs = item["incorrect_answers"]
    answers = wrongs + correct
    shuffle(answers)
    correct_id = answers.index(correct[0]) + 1
    for i in range(len(answers)):
        print(f" - {i+1} : {html.unescape(answers[i])}")
    try:
        user_answer = int(input("Your answer : "))
        if user_answer == correct_id:
            print("Correct!")
            score += 1
        else:
            print("Wrong!")
    except:
        print("Wrong!")

print(f"Score = {score}/{num_questions}")
