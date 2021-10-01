def bubble_sort(lst):
    n = len(lst)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if lst[j] > lst[j + 1]:
                lst[j + 1], lst[j] = lst[j], lst[j + 1]
    return lst


number_list = [int(x) for x in input("Enter list of number seperated by space ").split()]
print(f'Number list: {number_list}')
print(f'Sorted list: {bubble_sort(number_list)}')
