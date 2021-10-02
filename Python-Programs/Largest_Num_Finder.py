# Largest_Num_Finder
a = float(input("enter the first number"))
b = float(input("enter the second number"))
c = float(input("enter the third number"))
if a > b and a > c:
    largest = a
elif b > a and b > c:
    largest = b
elif c > a and c > b:
    largest = c
else:
    largest = "none"
print("The largest number is", largest)
