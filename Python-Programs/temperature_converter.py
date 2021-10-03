# a simple script which takes fahrenheit from user and convert it to celsius
def convert(s):
    f = float(s)
    c = (f - 32) * 5 / 9
    return c


print(convert(input("Enter fahrenheit: ")))
