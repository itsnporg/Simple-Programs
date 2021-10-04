def rotate(A, n):
    temp = A[n - 1]
    for i in range(len(A)):
        A[n - i - 1] = A[n - i - 2]
    A[0] = temp
    return A


A = [1, 2, 3, 4, 5]
print(rotate(A, len(A)))
