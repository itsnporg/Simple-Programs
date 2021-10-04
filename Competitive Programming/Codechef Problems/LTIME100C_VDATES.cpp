/*

Vaccine Dates Problem Code: VDATESSolvedSubmit (Practice)
Read problem statements in Mandarin, Bengali, Russian, and Vietnamese as well.
Chef has taken his first dose of vaccine D days ago. He may take the second dose no less than L days and no more than R days since his first dose.

Determine if Chef is too early, too late, or in the correct range for taking his second dose.

Input Format
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, three integers D,L,R.
Output Format
For each test case, print a single line containing one string - "Too Early" (without quotes) if it's too early to take the vaccine, "Too Late" (without quotes) if it's too late to take the vaccine, "Take second dose now" (without quotes) if it's the correct time to take the vaccine.

Constraints
1≤T≤105
1≤D≤109
1≤L≤R≤109
Subtasks
Subtask 1 (100 points): Original constraints
Sample Input 1 
4
10 8 12 
14 2 10
4444 5555 6666 
8 8 12
Sample Output 1 
Take second dose now
Too Late
Too Early
Take second dose now
Explanation
Test case 1: The second dose needs to be taken within 8 to 12 days and since the Day 10 lies in this range, we can take the second dose now.

Test case 2: The second dose needs to be taken within 2 to 10 days since Day 14 lies after this range, it is too late now.

Test case 3: The second dose needs to be taken within 5555 to 6666 days and since the Day 4444 lies prior to this range, it is too early now.

*/


#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t, l, d, r;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> d;
	    cin >> l;
	    cin >> r;

	    if(l>d)
	    {
	        cout << "Too Early\n";
	        continue;
	    }
	    else if(r < d)
	    {
	        cout << "Too Late\n";
	    }
	    else if(l<=d && r>=d)
	    {
	        cout << "Take second dose now\n";
	        continue;
	    }
	    
	}
	return 0;
}
