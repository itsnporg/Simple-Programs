/*

The Preparations Problem Code: SUPCHEFSolvedSubmit (Practice)
Chef has an exam which will start exactly M minutes from now. However, instead of preparing for his exam, Chef started watching Season-1 of Superchef. Season-1 has N episodes, and the duration of each episode is K minutes.

Will Chef be able to finish watching Season-1 strictly before the exam starts?

Note: Please read the explanations of the sample test cases carefully.

Input Format
The first line contains an integer T denoting the number of test cases. T test cases then follow.
The first and only line of each test case contains 3 space separated integers M, N and K.
Output Format
For each test case, output on one line YES if it is possible to finish Season-1 strictly before the exam starts, or NO if it is not possible to do so.

Output is case insensitive, which means that "yes", "Yes", "YEs", "no", "nO" - all such strings will be acceptable.

Constraints
1≤T≤104
1≤M≤109
1≤N,K≤104
Sample Input 1 
3
10 1 10
25 2 10
15 2 10
Sample Output 1 
NO
YES
NO
Explanation
Test Case 1: The duration of the only episode is 10 minutes, and the exam starts exactly after 10 minutes. So, Chef will not be able to finish watching Season-1 strictly before the exam starts.

Test Case 2: There are two episodes in Season-1, each of duration 10 minutes. Therefore, Chef will require 10+10=20 minutes to finish watching Season-1. As the exam starts after 25 minutes, Chef will be able to finish watching Season-1 strictly before the exam starts.

Test Case 3: There are two episodes in Season-1, each of duration 10 minutes. Therefore, Chef will require 10+10=20 minutes to finish watchin Season-1. As the exam starts after 15 minutes, Chef will not be able to finish watching Season-1 strictly before the exam starts.


*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t, m, n, k;
	
	cin >> t;
	
	while(t--)
	{
	    
	    cin >> m >> n >> k;
	    if(m > (n*k))
	    {
	        std::cout << "YES" << std::endl;
	    }
	    else
	    {
	        std::cout << "NO" << std::endl;
	    }
	    
	}
	return 0;
	
}
