/*
Odd GCD Problem Code: BININVERSolvedSubmit (Practice)
You are given an array A1,A2,…,AN consisting of N integers. Your goal is to make the GCD of all the elements in the array an odd integer. To achieve this goal, you can do the following operation any number of times:

Choose an index i(1≤i≤N) such that Ai>1 and set Ai=⌊Ai2 ⌋
You can choose an index multiple times during the operations. Find the minimum number of operations after which GCD of all the elements in the array becomes an odd integer.

Note: ⌊x⌋ : Returns the largest integer that is less than or equal to x (i.e rounds down to the nearest integer). For example, ⌊1.5⌋=1,⌊2⌋=2, ⌊72 ⌋ =⌊3.5⌋ =3.

Input Format
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.
Output Format
For each test case, print a single line containing one integer - the minimum number of operations after which GCD of all the elements in the array becomes an odd integer.

Constraints
1≤T≤103
1≤N≤105
1≤Ai≤109
Sum of N over all test cases does not exceed 5⋅105
Sample Input 1 
3
3
2 3 5
2
4 6
3 
4 12 24
Sample Output 1 
0
1 
2

*/



#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t, n, min, counter, temp;
	long long int* myarray;
	
	cin >> t;
	
	while(t--)
	{
	    min = INT_MAX;
	    cin >> n;
	    myarray = new long long int[n];
	    
	    for(int i=0; i<n; i++)
	    {
	        cin >> temp;
	        counter = 0;
	        myarray[i] = temp;
	        
	        while(!(temp&1))
	        {
	            temp /= 2;
	            counter += 1;
	        }
	        
	        if(counter < min)
	        {
	            min = counter;
	        }
	        
	    }
	    
	    
	    std::cout << min << std::endl;
	    delete[] myarray;
	}
	return 0;
}
