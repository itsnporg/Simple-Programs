import heapq
from heapq import *


def find_kth_smallest(A, k):
    heapq.heapify(A)  # by deafult heapify makes a min heap
    while (
        k > 1
    ):  # we will pop upto k-1 times so that the kth min will be at top after (k-1)th iteration
        heappop(A)
        k -= 1
    return A[0]


A = [7, 4, 6, 3, 9, 1]
k = 3
print("k'th smallest element in the list is", find_kth_smallest(A, k))
