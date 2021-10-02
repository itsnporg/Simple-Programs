/*

Prefix Sums Problem Code: UNQEQSolvedSubmit (Practice)
Read problem statements in Mandarin, Bengali, Russian, and Vietnamese as well.
For a positive, even integer N, we call a pair of arrays A and B to be interesting if they satisfy the following conditions :

|A|=|B|=N/2 i.e. the length of array A is equal to the length of array B.

Each integer from 1 to N occurs exactly once in exactly one of the arrays.

The ith prefix sum of A is not equal to ith prefix sum of B for all 1≤i≤N/2−1. Formally, ∑j=1iAj≠∑j=1iBj for all 1≤i≤N/2−1
Sum of all elements in A is equal to sum of all elements in B i.e. ∑j=1N/2Aj=∑j=1N/2Bj
You are given a positive, even integer N. If there exists an interesting pair of arrays, then print "YES" followed by an interesting pair for this given N. If there exists multiple interesting pairs of arrays for given N, you can print any. Print "NO" in a single line if no such pair exists.

Input Format
First line of input will contain T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, the integer N.
Output Format
For each test case, if there exists an interesting pair of arrays, say (A,B), then in the first line print "YES", in the second line print array A separated by spaces, and in third line print array B separated by spaces. Print "NO" in a single line if no such pair exists. If there are multiple answers, print any of them.

Constraints
1≤T≤105
1≤N≤105
N is guaranteed to be even.
Sum of N over all test cases doesn't exceed 106
Subtasks
Subtask 1 (100 points): Original constraints
Sample Input 1 
2
2
4
Sample Output 1 
NO
YES
1 4
2 3
Explanation
Test case 2: Consider A=[1,4] and B=[2,3]. Every integer from 1 to 4 occurs exactly once in exactly one of the arrays. Also, 1st prefix sum of A is not equal to 1st prefix sum of B (1≠2). And sum of the elements is equal to 5 for both arrays. So, (A,B) is an interesting pair.

*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t, n;
	int q1, q2, q3, q4;
	cin >> t;
	
	while(t--)
	{
	    cin >> n;
	    if(n%4 == 0)
	    {
	        //     0........q1.q3........q4.q2.......n
	        cout << "YES\n";
	        q1 = (n/4);
	        q2 = ((3*n)+4)/4;
	        for(int i=1; i<=q1; i++)
	        {
	            cout << i << " ";
	        }
	        
	        for(int i=q2; i<=n; i++)
	        {
	            cout << i << " ";
	        }
	        cout << "\n";
	        
	        
	        q3 = q1 + 1;
	        q4 = q2 - 1;
	        
	        for(int i=q3; i<=q4; i++)
	        {
	            cout << i << " ";
	        }
	        cout << "\n";
	    }
	    else
	    {
	        cout << "NO\n";
	    }
	}
	return 0;
}


