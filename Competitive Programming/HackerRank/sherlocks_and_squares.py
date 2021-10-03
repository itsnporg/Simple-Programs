'''
https://www.hackerrank.com/challenges/sherlock-and-squares/problem

'''

import os
import random
import re
import sys

# Complete the squares function below.
def squares(a, b):
    sqrta = math.ceil(math.sqrt(a))  # find the sqrt of lower number
    sqrtb = math.floor(math.sqrt(b)) # find the sqrt of upper number
    return(sqrtb - sqrta + 1)  # return the difference of them and add 1
    
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        ab = input().split()

        a = int(ab[0])  # take the lower number input

        b = int(ab[1])  # take the upper number input

        result = squares(a, b) # pass these as parameters

        fptr.write(str(result) + '\n')

    fptr.close()



