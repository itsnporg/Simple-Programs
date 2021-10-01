def partition(lst, low, high):
    i = (low - 1) 
    pivot = lst[high] 
    for j in range(low, high):
        if lst[j] < pivot:
            i = i + 1
            lst[i], lst[j] = lst[j], lst[i]

    lst[i + 1], lst[high] = lst[high], lst[i + 1]
    return i + 1


def quick_sort(lst, low, high):
    if low < high:
        pi = partition(lst, low, high)
        quick_sort(lst, low, pi - 1)
        quick_sort(lst, pi + 1, high)
    return lst


number_list = [int(x) for x in input("Enter list of number separated by space ").split()]
print(f'Number list: {number_list}')
print(f'Sorted list: {quick_sort(number_list, 0, len(number_list) - 1)}')
