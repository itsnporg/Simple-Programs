/*


Magical Doors Problem Code: MAGDOORSSolvedSubmit (Practice)
Chef wants to cross a hallway of N doors. These N doors are represented as a string. Each door is initially either open or close, represented by 1 or 0 respectively. Chef is required to go through all the doors one by one in the order that they appear, starting from the leftmost door and moving only rightwards at each step.

To make the journey easier, Chef has a magic wand, using which Chef can flip the status of all the doors at once. Determine the minimum number of times Chef has to use this wand to cross the hallway of doors.

For example, the doors are 10011. Chef will start from the left and enter the first door. After passing through that door, the magic wand is waved. This flips the string to 01100. Now Chef passes through the next two doors in one go. Again, just before reaching the 4th door, the magic wand is waved. Now that the string is in its original state, Chef passes through the last two doors as well. The minimum number of times the magic wand needed to be used here was 2.

Input Format
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single string S, representing the doors as given in the problem.
Output Format
For each test case, print a single line containing one integer denoting the minimum number of times the magic wand needs to be used.

Constraints
1≤T≤105
1≤|S|≤105
Sum of |S| over all test cases ≤2⋅106
Sample Input 1 
3
111
010
10011
Sample Output 1 
0
3
2
Explanation
Test Case 1: Since all the doors are already open, Chef doesn't need to use the magic wand at all.
Test Case 2: Chef will use the wand the first time to open door 1. This operation makes the string "101". Chef again needs to use the wand to open door 2, and then one last time to open door 3. In total, Chef used the wand 3 times.
Testcase 3: As explained in the problem statement above.

*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t, waves, n;
	string s;
	cin >> t;
	
	while(t--)
	{
	    cin >> s;
	    waves = 0;
	    n = s.length();
	    
	    for(int i=0; i<n; i++)
	    {
	        if( (s[i]=='0') && (waves%2==0) )
	        {
	            waves += 1;
	        }
	        else if((s[i]=='1') && (waves%2==1))
	        {
	            waves += 1;
	        }
	    }
	    
	    std::cout << waves << std::endl;
	}
	return 0;
}
