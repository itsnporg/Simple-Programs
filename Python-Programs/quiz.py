#simple quiz 

print("Simple quiz")

# asking the user if he/she wants to play 

playing = input("Do you want to play? ")

if playing.lower() != "yes":
    quit()

print("Okay! Let's play :)")
score = 0

answer = input("What does HTML stand for? ")
if answer.lower() == "hypertext markup language":
    print('Correct!')
    score += 1
else:
    print("Incorrect!")

answer = input("What does CSS stand for? ")
if answer.lower() == "cascading style sheets":
    print('Correct!')
    score += 1
else:
    print("Incorrect!")

answer = input("What does RAM stand for? ")
if answer.lower() == "random access memory":
    print('Correct!')
    score += 1
else:
    print("Incorrect!")

answer = input("What does JS stand for? ")
if answer.lower() == "javascript":
    print('Correct!')
    score += 1
else:
    print("Incorrect!")

print("You got " + str(score) + " questions correct!")
print("You got " + str((score / 4) * 100) + "%.")
