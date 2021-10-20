def sort012(a):
    low = 0
    middle = 0
    high = len(a) - 1
    while middle <= high:
        if a[middle] == 0:
            a[middle], a[low] = a[low], a[middle]
            middle += 1
            low += 1
        elif a[middle] == 1:
            middle += 1
        else:
            a[middle], a[high] = a[high], a[middle]
            middle += 1
            high -= 1
    return a


arr = [0, 2, 1, 2, 0]
print(sort012(arr))
