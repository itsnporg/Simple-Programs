# Python program to reverse a number using function
def reverse_num(number):  # Define a function
    reverse = 0  # declarae and initialize variable Reserve
    while number > 0:
        reminder = number % 10
        reverse = (reverse * 10) + reminder
        number = number // 10
    return reverse  # return reverse value to function


number = int(input("Please enter a number: "))
reverse = reverse_Num(number)  # Call the function
print("The entered number is: %d" % number)
print("The reverse number is: %d" % reverse)
