import random
print("#------------------#")
print("| GUESS THE NUMBER |")
print("#------------------#")
print('\n')


print('Range of Random Numbers.')
start = int(input('Enter Starting Index: '))
end = int(input('Enter Ending Index: '))
number = random.randint(start, end)
print('\n')


while True:
    guess = int(input('Guess the number:  '))
    if guess > number:
        print('\nUmmm, try a lower number...\n')

    elif guess < number:
        print('\nGo a little higher\n')

    else:
        print("Right on! Well done!")
        break
