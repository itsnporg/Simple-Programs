/*

Make it Divisible Problem Code: MAKEDIV3SolvedSubmit (Practice)
Given an integer N, help Chef in finding an N-digit odd positive integer X such that X is divisible by 3 but not by 9.

Note: There should not be any leading zeroes in X. In other words, 003 is not a valid 3-digit odd positive integer.

Input Format
The first line of input contains a single integer T, denoting the number of testcases. The description of the T testcases follows.
The first and only line of each test case contains a single integer N, denoting the number of digits in X.
Output Format
For each testcase, output a single line containing an N-digit odd positive integer X in decimal number system, such that X is divisible by 3 but not by 9.

Constraints
1≤T≤500
1≤N≤104
The sum of N over all test cases does not exceed 105
Sample Input 1 
3
1
2
3
Sample Output 1 
3
15
123
Explanation
Test Case 1: 3 is the only 1-digit odd positive integer which is divisible by 3 but not by 9.

Test Case 2: 15 is a 2-digit odd positive integer which is divisible by 3 but not by 9. 21 is also a valid answer, among others. Note that 03 is not a valid answer as there should not be any leading zeroes in the output.
*/


#include <iostream>
using namespace std;

int main() {
    
	// your code goes here
	int t, n;
	cin >> t;
	while(t--)
	{
	    cin >> n;
	    for(int i=0; i<(n-1); i++)
	    {
	        cout << 3;
	    }
	    
	    if(n%3==0)
	    {
	        cout << 9;
	    }
	    else
	    {
	        cout << 3;
	    }
	    cout << "\n";
	}
	return 0;
}
