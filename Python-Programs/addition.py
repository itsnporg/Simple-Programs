# Python program for addition of two numbers

# function for addition
def add(x,y):
	return x+y

# Main program

first, second = [int(x) for x in input("Enter two value: ").split()]

sum = add(first,second)

print(f"The sum is {sum}")
