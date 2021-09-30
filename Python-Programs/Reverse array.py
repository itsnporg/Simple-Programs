#Reverse an array
#Approach 1:

def reverse(A,start,end):
    while start< end:
        A[start],A[end]=A[end],A[start]
        start +=1
        end -=1

A= [1,2,3,4,5,6]
print(A)
reverse(A,0,5)
print("Reversed list is: ")
print(A)
    
#Approach 2:

def reverse(A):
    print(A[::-1])

A=[1,2,3,4,5,6]
print(A)
print("Reversed List is: ")
reverse(A)
