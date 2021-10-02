def selection_sort(items_list):
    n = len(items_list)
    for i in range(n - 1):
        min_value_index = i

        for j in range(i + 1, n):
            if items_list[j] < items_list[min_value_index]:
                min_value_index = j

        if min_value_index != i:
            temp = items_list[i]
            items_list[i] = items_list[min_value_index]
            items_list[min_value_index] = temp

    return items_list


_list = [21, 6, 9, 33, 3]

print(selection_sort(_list))
