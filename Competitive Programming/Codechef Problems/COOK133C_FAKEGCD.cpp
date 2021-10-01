/*

Fake GCD Problem Code: FAKEGCDSolvedSubmit (Practice)
Read problems statements in Russian and Bengali.
You are given an integer N. Output a permutation of values from 1 to N that satisfies the following condition:

gcd([1+A1,2+A2,3+A3,…,N+AN])>1
It can be proven that a solution always exists. If there are multiple permutations that can satisfy the condition, then output any one of them.

As a reminder,

A permutation of values from 1 to N is an array containing integers from 1 to N in any order but each of them appearing exactly once.
GCD stands for Greatest Common Divisor. The greatest common divisor of a sequence is the largest integer d such that all the numbers in sequence are divisible by d. For more information, refer to here.
Input Format
The first line contains an integer T denoting the number of test cases. The T test cases then follow.
The first line of each test case contains an integer N.
Output Format
For each test case, output on one line a permutation of values from 1 to N which satisfies the above condition.

Constraints
1≤T≤500
2≤N≤500
Sample Input 1 
1
4
Sample Output 1 
3 4 1 2
Explanation
For the first test case, gcd([1+3,2+4,3+1,4+2])=gcd([4,6,4,6])=2 which is greater than 1, so the given permutation satisfies the condition.
*/

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	//bruuuuh... Cheap easy question. 
	//I am fkin out of my mind today. Spent 15 min on this shit.
	
	int t, n;
	cin >> t;
	while(t--)
	{
	    cin >> n;
	    for(int i=0; i<n; i++)
	    {
	        cout << i+1 << " ";
	    }
	
	    cout << "\n";
	}
	return 0;
}
