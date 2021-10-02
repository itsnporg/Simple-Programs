number = int(input("Enter The Number"))

if number > 1:
    for i in range(2,int(number/2)+1):
        if (number % i == 0):
            print(number, "is not a Prime Number")
            break
    else:
        print(number,"is a Prime number")
# If the number is less than 1 it can't be Prime    
else:
    print(number,"is not a Prime number")