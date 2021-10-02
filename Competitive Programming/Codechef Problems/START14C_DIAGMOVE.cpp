/*

Diagonal movement Problem Code: DIAGMOVESolvedSubmit (Practice)
Given the coordinates (x,y) of a point in 2-D plane. Find if it is possible to reach (x,y) from (0,0). The only possible moves from any coordinate (i,j) are as follows:

Go to the point with coordinates (i+1,j+1).
Go to the point with coordinates (i+1,j−1)
Go to the point with coordinates (i−1,j+1).
Go to the point with coordinates (i−1,j−1).
Input Format
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, two integers x,y.
Output Format
For each test case, print YES if it is possible to reach (x,y) from (0,0), otherwise print NO.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤2⋅104
−109≤x,y≤109
Sample Input 1 
6
0 2
1 2
-1 -3
-1 0
-3 1
2 -1
Sample Output 1 
YES
NO
YES
NO
YES
NO
Explanation
Test case 1: A valid sequence of moves can be: (0,0)→(1,1)→(0,2).

Test case 2: There is no possible way to reach the point (1,2) from (0,0).

Test case 3: A valid sequence of moves can be: (0,0)→(−1,−1)→(0,−2)→(−1,−3).


*/


#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t, x, y, sum;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> x >> y;
	    sum = x+y;
	    sum = abs(sum);
	    if(sum&1)
	    {
	        cout << "NO\n";
	    }
	    else
	    {
	        cout << "YES\n";
	    }
	    
	}
	return 0;
}
