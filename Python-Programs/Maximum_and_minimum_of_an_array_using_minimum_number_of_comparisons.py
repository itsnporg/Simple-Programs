def findMinAndMax(A):
    min, max = A[0], A[0]
    for i in range(1, len(A)):
        if min > A[i]:
            min = A[i]
        elif max < A[i]:
            max = A[i]
    print("Min And Max: ", min, max)


A = [5, 7, 2, 4, 9, 6]
findMinAndMax(A)
