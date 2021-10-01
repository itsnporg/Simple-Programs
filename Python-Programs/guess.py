# Program to generate a random number between 0 and 9

# importing the random module
import random

secret_num = random.randint(0, 9)
guess = ""
guess_count = 0
guess_limit = 3
out_of_guess = False

while guess != secret_num and not (out_of_guess):
    if guess_count < guess_limit:
        guess = float(input("Enter your guess : "))
        guess_count += 1
    else:
        out_of_guess = True
if out_of_guess:
    print("out of guess! You Loose")
else:
    print("You win!")
