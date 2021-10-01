def merge_sort(lst):
    if len(lst) > 1:
        mid = len(lst) // 2
        last = lst[:mid]
        first = lst[mid:]
        merge_sort(last)  
        merge_sort(first)
        i = j = k = 0

        while i < len(last) and j < len(first):
            if last[i] < first[j]:
                lst[k] = last[i]
                i += 1
            else:
                lst[k] = first[j]
                j += 1
            k += 1
        while i < len(last):
            lst[k] = last[i]
            i += 1
            k += 1
        while j < len(first):
            lst[k] = first[j]
            j += 1
            k += 1
    return lst


number_list = [int(x) for x in input("Enter list of number seperated by space ").split()]
print(f'Number list: {number_list}')
print(f'Sorted list: {merge_sort(number_list)}')