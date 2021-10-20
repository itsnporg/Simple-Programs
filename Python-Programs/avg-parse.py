# Total, Average and Count Computation from numbers in a text file with a mix of words and numbers

fname = input("Enter file name: ")
# Ensure your file is in the same folder as this script
# Test file used here is mbox.txt
fhandle = open(fname)

# Seeking number after this word x
x = "X-DSPAM-Confidence:"
y = len(x)

# This shows that the total number of characters is 19
print(y)

# This would show that character 19 is ':' where you can slice to get the numbers after that
print(x[18:])

# Create count to count number of numbers
count = 0
# Create total to sum all the numbers
total = 0

for line in fhandle:
    if line.startswith(x):
        # Slice the number from the sentence
        line_number = line[19:]
        line_number = float(line_number)

        # print(line_number)
        # This shows that we have successfully extracted the floating numbers

        # Loop, iterates through all numbers to count number of numbers
        count += 1

        # Loop, iterates through all numbers to count sum of numbers
        total += line_number

print("Count of numbers", count)
print("Sum of numbers", total)
print("Average of numbers", total / count)
