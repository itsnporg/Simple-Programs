
'''

In this challenge, the user enters a string and a substring.
You have to print the number of times that the substring occurs
in the given string. String traversal will take place from left to right, not from right to left.

'''
def count_substring(string, sub_string):
    stri = []
    for i in range(len(string)):
        stri.append(string[i:i+len(sub_string)])
    return stri.count((sub_string))

    

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)