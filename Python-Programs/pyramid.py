x = int(input("Enter a number: "))
strrspace = " "
strr = " #"
for i in range(1, x + 1):
    if i == x:
        print("#" + (i - 1) * strr)
    else:
        print(((x - 1) - (i)) * strrspace, "#" + (i - 1) * strr)
