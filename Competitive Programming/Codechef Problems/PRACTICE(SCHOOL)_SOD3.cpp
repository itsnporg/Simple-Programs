/*

Yet another SOD problem Problem Code: SOD3SolvedSubmit
Read problem statements in Mandarin, Bengali, Russian, and Vietnamese as well.
Ujan is a software developer. He is developing a software that takes two integers L and R and outputs the count of integers in the sequence L,L+1,…,R−1,R whose sum of digits (SOD) is divisible by 3.

He has developed the user interface (UI) quite easily. He is having a hard time finding the logic to solve the problem. As you are not only a good friend of Ujan but also a good problem solver, he asks you to help him out.

Can you solve the problem for your friend, Ujan?

Input Format
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The only line of each test case contains two integer L,R.
Output Format
For each test case, print a single line containing one integer equal to the count of of integers in the sequence, whose sum of digits is divisible by 3 .

Constraints
1≤T≤104
1≤L≤R≤1018
Subtasks
Subtask 1 (100 points): Original constraints
Sample Input 1 
5
139 141
100 1235
1000 2537
998244353 1000000007
27182818284 31415926535897
Sample Output 1 
1
378
512
585218
10462914572538
Explanation
Test case 1: The numbers are 139, 140 and 141. Their sum of digits is 13, 5 and 6 respectively. So, only 141 is the number that has its sum of digits divisible by 3.


*/

#include <iostream>
using namespace std;
int main(void) {
	// your code goes here
	unsigned long long int t, l, r;
	cin >> t;
	while(t--)
	{
	    cin >> l >> r;
	    cout << (r/3)-(l-1)/3 << "\n";
	}
	return 0;
}

