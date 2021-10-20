"""
program to generate fibonacci series
"""

# Recursive approach
def fibonacci(n):
    """
    - recursie approach
    - return the fibonacci number
      at the given index
    """
    # Check if n is valid
    if n < 0:
        print("Enter a positive number")

    elif n == 0:
        return 0

    elif n == 1 or n == 2:
        return 1

    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


# Iterative approach
def fibonacci(n):
    """
    - iterative approach
    - return the fibonacci number
      at the given index
    """
    # Take first two numbers as 0 & 1
    t1, t2 = 0, 1

    # check if n is valid
    if n < 0:
        print("Enter a positive number")

    elif n == 0:
        return 0

    elif n == 1:
        return t2

    else:
        # generate series
        for i in range(1, n):
            t3 = t1 + t2
            t1 = t2
            t2 = t3

        return t3
