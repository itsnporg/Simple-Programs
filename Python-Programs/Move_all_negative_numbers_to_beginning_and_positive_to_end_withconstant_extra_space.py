def rearrange(a):
    negative = 0
    positive = 0
    while positive < len(a):
        if a[positive] < 0:
            a[positive], a[negative] = a[negative], a[positive]
            positive += 1
            negative += 1
        else:
            positive += 1
    return a


arr = [-2, -3, 4, 5, 6, -7, 8, 9]
print(rearrange(arr))
