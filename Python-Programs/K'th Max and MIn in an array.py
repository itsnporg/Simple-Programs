# Kth max and min element of an array.

n = int(input())
arr = input()   # takes the whole line of n numbers
l = list(map(int,arr.split(' '))) 
kth = int(input())
l.sort()
print(l[kth-1])
print(l[len(l)-kth-1])
