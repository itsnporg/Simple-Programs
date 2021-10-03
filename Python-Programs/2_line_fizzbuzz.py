i = 1
while i < 101:
    print("Fizz" * (i % 3 < 1) + (i % 5 < 1) * "Buzz" or i)
    i += 1
