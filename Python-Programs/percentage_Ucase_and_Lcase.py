# How to check percentage of lower and upper case letter?
string = input('Enter any string: ')
upper = 0
lower = 0
for letter in string:
    if letter.isupper():
        upper += 1
    elif letter.islower():
        lower += 1
    else:
        continue
u_perc = upper * 100/(upper + lower)
l_perc = lower * 100/(upper + lower)
print(f'Lowercase({lower}) : {round(u_perc,2)}%')
print(f'Uppercase({upper}) : {round(l_perc,2)}%')