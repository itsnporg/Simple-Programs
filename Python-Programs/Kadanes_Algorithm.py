def maxSubArraySum(arr):
    sum = arr[0]
    maximum = arr[0]
    for i in range(1, len(arr)):
        if (sum + arr[i]) > arr[i]:
            sum += arr[i]
            maximum = max(maximum, sum)
        else:
            sum = arr[i]
            maximum = max(maximum, sum)
    return maximum


arr = [1, 2, 3, -2, 5]
print(maxSubArraySum(arr))
