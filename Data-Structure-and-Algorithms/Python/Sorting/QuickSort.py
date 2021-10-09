def partition(arr, low, high):
    pivot = arr[high]
    i = low -1
    for j in range(low, high):
        if arr[j] <= pivot:
            i +=1
            (arr[i], arr[j]) = (arr[j], arr[i])
    (arr[i+1], arr[high]) =(arr[high], arr[i+1])            
    return i + 1

def quickSort(array, low, high):
  if low < high:
    pi = partition(array, low, high)
    quickSort(array, low, pi - 1)
    quickSort(array, pi + 1, high)
if __name__ == '__main__':
    data = [8, 7, 2, 1, 0, 9, 6]
    print("Unsorted: ")
    print(data)
    quickSort(data, 0, len(data) - 1)
    print('Sorted:')
    print(data)