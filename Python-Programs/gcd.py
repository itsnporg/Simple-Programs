def GCD(x, y):
    if (x % y) == 0:
        return y
    else:
        return GCD(y, x % y)


print("GCD is ", GCD(80, 12))
