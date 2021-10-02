##Simple Calculator Using Python

print("Welcome to the calculator!")
print("+ for addition,\n - for subtraction,\n * for multiplication,\n / for division")

while True:
    print("Type your first number below, e.g. 1")
    x = float(input())
    print("Type your operator below, e.g. +, plus, add etc. for addition")
    operator = input()
    print("Type your second number, e.g. 2")
    y = float(input())
    print("Thank you, the calculator is calculating!...")
    ##print results
    if operator == "+" or operator == "plus" or operator == "add":
        print("The answer is =", x + y)
    if operator == "-" or operator == "minus" or operator == "subtract":
        print("The answer is =", x - y)
    if (
        operator == "*"
        or operator == "x"
        or operator == "times"
        or operator == "multiply"
    ):
        print("The answer is =", x * y)
    if operator == "/" or operator == "divide":
        print("The answer is =", x / y)
    print("......................................................")
    print("If you want to exit, enter ctrl^c")
    print("continuing....")
