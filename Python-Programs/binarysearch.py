def binarysearch(arr, n):
    low = 0
    high = len(arr) - 1
    mid = 0
    while low <= high:
        mid = (high + low) // 2
        if arr[mid] < n:
            low = mid + 1
        elif arr[mid] > n:
            high = mid - 1
        else:
            return mid
    return "doesnt exist!"


if __name__ == "__main__":
    print(
        binarysearch(
            input("enter the list: ").split(","), input("you want to search for: ")
        )
    )
