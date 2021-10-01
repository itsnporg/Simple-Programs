def insertion_sort(lst):
    n = len(lst)
    for i in range(1, n):
        temp = lst[i]
        j = i - 1
        while temp < lst[j] and j >= 0:
            lst[j+1] = lst[j]
            j -= 1
        lst[j+1] = temp
    return lst


number_list = [int(x) for x in input("Enter list of number separated by space ").split()]
print(f'Number list: {number_list}')
print(f'Sorted list: {insertion_sort(number_list)}')
