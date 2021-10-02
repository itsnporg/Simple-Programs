import random
# Split string method
names_string = input("Give me everybody's names, separated by a comma. ")
names = names_string.split(", ")
# Don't change the code above 

# Write your code below this line 

name_length = len(names)
random_name = random.randint(0, name_length - 1)
person_who_will_pay = names[random_name]
print(person_who_will_pay + " is going to pay bill.")