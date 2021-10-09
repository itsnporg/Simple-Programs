def mergeSort(arr):
    if len(arr) > 1:
        midval = len(arr)//2
        LH = arr[:midval]
        RH = arr[midval:]
        mergeSort(LH)
        mergeSort(RH)
        i = j = k = 0
        while i < len(LH) and j < len(RH):
            if LH[i] < RH[j]:
                arr[k] = LH[i]
                i += 1
            else:
                arr[k] = RH[j]
                j += 1
            k += 1
        while i < len(LH):
            arr[k] = LH[i]
            i += 1
            k += 1
        while j < len(RH):
            arr[k] = RH[j]
            j += 1
            k += 1
if __name__ == '__main__':
    arr = [12, 11, 13, 5, 6, 7]
    print("Given array is: ", arr)
    mergeSort(arr)
    print("Sorted array is: ", arr)