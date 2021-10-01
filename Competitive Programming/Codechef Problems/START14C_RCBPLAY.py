# RCB and Playoffs Problem Code: RCBPLAYSolvedSubmit (Practice)
# Team RCB has earned X points in the games it has played so far in this year's IPL. To qualify for the playoffs they must earn at least a total of Y points. They currently have Z games left, in each game they earn 2 points for a win, 1 point for a draw, and no points for a loss.

# Is it possible for RCB to qualify for the playoffs this year?

# Input Format
# First line will contain T, number of testcases. Then the testcases follow.
# Each testcase contains of a single line of input, three integers X,Y,Z.
# Output Format
# For each test case, output in one line YES if it is possible for RCB to qualify for the playoffs, or NO if it is not possible to do so.

# Output is case insensitive, which means that "yes", "Yes", "YEs", "no", "nO" - all such strings will be acceptable.

# Constraints
# 1≤T≤5000
# 0≤X,Y,Z≤1000
# Sample Input 1
# 3
# 4 10 8
# 3 6 1
# 4 8 2
# Sample Output 1
# YES
# NO
# YES
# Explanation
# Test Case 1: There are 8 games remaining. Out of these 8 games, if RCB wins 2 games, loses 4 games and draws the remaining 2 games they will have a total of 10 points, this shows that it is possible for RCB to qualify for the playoffs.

# Note: There can be many other combinations which will lead to RCB qualifying for the playoffs.

# Test Case 2: There is no way such that RCB can qualify for the playoffs.

# Test Case 3: If RCB wins all their remaining games, they will have end up with 8 points. (4+2∗2=8), hence it is possible for them to qualify for the playoffs.


t = int(input())

for i in range(t):
    # x = int(input())
    # y = int(input())
    # z = int(input())
    x, y, z = input().split()
    x = int(x)
    y = int(y)
    z = int(z)

    if (x + 2 * z) >= y:
        print("YES")
    else:
        print("NO")
