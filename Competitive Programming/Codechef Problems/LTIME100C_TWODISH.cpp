/*

Two Dishes Problem Code: TWODISHSolvedSubmit (Practice)
Read problem statements in Mandarin, Bengali, Russian, and Vietnamese as well.
Chef will have N guests in his house today. He wants to serve at least one dish to each of the N guests. Chef can make two types of dishes. He needs one fruit and one vegetable to make the first type of dish and one vegetable and one fish to make the second type of dish. Now Chef has A fruits, B vegetables, and C fishes in his house. Can he prepare at least N dishes in total?

Input Format
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, four integers N,A,B,C.
Output Format
For each test case, print "YES" if Chef can prepare at least N dishes, otherwise print "NO". Print the output without quotes.

Constraints
1≤T≤100
1≤N,A,B,C≤100
Subtasks
Subtask 1 (100 points): Original constraints
Sample Input 1 
4
2 1 2 1
3 2 2 2
4 2 6 3
3 1 3 1
Sample Output 1 
YES
NO
YES
NO
Explanation
Test case 1: Chef prepares one dish of the first type using one fruit and one vegetable and another dish of the second type using one vegetable and one fish.

Test case 2: Chef prepares two dishes of the first type using two fruit and two vegetable. Now all the vegetables are exhausted, hence he can't prepare any other dishes.

Test case 3: Chef can prepare a total of 5 dishes, two dishes of the first type and three dishes of the second type.

*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t, n, a, b, c;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> n >> a >> b >> c;
	    if(b>=n && (a+c) >=n)
	    {
	        cout << "YES\n";
	    }
	    else
	    {
	        cout << "NO\n";
	    }

	}
	return 0;
}



