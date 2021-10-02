# how to get number greater than average number in array.
from random import randint
x = 20
greater = []
array = []
total = 0
for i in range(x):
    array.append(randint(1, 500))
for i in array:
    total += i
    avg = total/x
for i in array:
    if avg < i:
        greater.append(i)
print(array)
print(f'Average of array is {avg}')
print(f'Greater than average : {greater}')