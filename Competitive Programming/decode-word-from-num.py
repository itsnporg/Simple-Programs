# A word was encoded by mapping each letter to an integer from 1 to 26.
# Find out the number of ways this number can be decoded back to a word.

# Example:
# 'bdg' maps to '247'
# '247' can be decoded to 'bdg' as well as 'xg'

# Sample input:
# 247

# Sample output:
# 2


encodedData = '247'

def num_ways(encodedData):

    if encodedData == '':
        return 1

    if encodedData[0] == '0':
        return 0

    ways = num_ways(encodedData[1:])

    if int(encodedData[:2]) <= 26 and int(encodedData[:2]) >= 10 :
        ways += num_ways(encodedData[2:])
    
    return ways

print(num_ways(encodedData))