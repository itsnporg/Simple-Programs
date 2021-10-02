/*

Find Second Largest Problem Code: SECLARSolvedSubmit
Given three distinct integers A, B and C, print the second largest number among them.

Input:
The input consists of three lines.
The first line contains a single integer A.
The second line contains a single integer B.
The third line contains a single integer C.
Output:
Print the second largest number among A, B and C, in a separate line.

Constraints
1≤A,B,C≤109
Sample Input 1:
2
7
21
Sample Output 1:
7
Sample Input 2:
14
28
16
Sample Output 2:
16
EXPLANATION:
In the first example, 7 is the second largest number among the given three numbers.
In the second example, 16 is the second largest number among the given three numbers.

*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	long long int t, a, b, c;
	
	cin >> a >> b >> c;
	    if((a>=b && b>=c) || (a<=b && b<=c))
	    {
	        cout << b << endl;
	    }
	    else if((b>=a && a>=c) || (b<=a && a<=c))
	    {
	        cout << a << endl;
	    }
	    else
	    {
	        cout << c << endl;
	    }
	return 0;
}
