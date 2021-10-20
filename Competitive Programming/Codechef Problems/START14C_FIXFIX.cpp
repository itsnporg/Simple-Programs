/*

Fixed number of Fixed Points Problem Code: FIXFIXSolvedSubmit (Practice)
Given a positive integer n and an integer k such that 0≤k≤n, find any permutation A of 1,2…n such that the number of indices for which Ai=i is exactly k. If there exists no such permutation, print −1. If there exist multiple such permutations, print any one of them.

Input Format
First line of the input contains T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, two integers n,k.
Output Format
For each test case, print a permutation in a single line, if a permutation with the given constraints exists. Print −1 otherwise.

Constraints
1≤T≤105
1≤n≤105
0≤k≤n
Sum of n over all test cases doesn't exceed 2⋅106
Sample Input 1 
3
2 1
3 1
4 2
Sample Output 1 
-1
1 3 2
3 2 1 4
Explanation
Test case 1: There are total 2 permutations of [1,2] which are [1,2] and [2,1]. There are 2 indices in [1,2] and 0 indices in [2,1] for which Ai=i holds true. Thus, there doesn't exist any permutation of [1,2] with exactly 1 index i for which Ai=i holds true.

Test case 2: Consider the permutation A=[1,3,2]. We have A1=1, A2=3 and A3=2. So, this permutation has exactly 1 index such that Ai=i.

*/


#include <bits/stdc++.h>
using namespace std;

int main() 
{
	long long int t, n, k;
	cin >> t;
	
	while(t--)
	{
	    cin >> n >> k;
	    if( k==1 && n==1 )
	    {
	        cout << 1;
	    }
	    else if(n==k)
	    {
	        for(int i=1; i<=n; i++)
	        {
	            cout << i << " ";
	        }
	    }
	    else if( n==(k+1) )
	    {
	        cout << -1;
	    }
	    else
	    {
	        
	        for(int i=1; i<=k; i++)
	        {
	            cout << i << " ";
	        }
	        for (int i = k+2; i <= n; i++) {
	            cout << i << " ";
	        }
	        cout << k+1 ;
	    }
	    
	    cout << "\n";
	    
	}
	return 0;
}
