# Creating a bubble sort function
def bubble_sort(unsorted_list):
    # Outer loop for traverse the entire list
    for i in range(0, len(unsorted_list) - 1):
        for j in range(len(unsorted_list) - 1):
            if unsorted_list[j] > unsorted_list[j + 1]:
                temp = unsorted_list[j]
                unsorted_list[j] = unsorted_list[j + 1]
                unsorted_list[j + 1] = temp
    return unsorted_list


unsorted_list = [5, 3, 8, 6, 7, 2]
print("The unsorted list is: ", unsorted_list)
print("The sorted list is: ", bubble_sort(unsorted_list))
