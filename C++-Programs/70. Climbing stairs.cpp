//Submitted by Harivams Sai Gudalwar (https://github.com/harivams-sai)
// Question link: https://leetcode.com/problems/climbing-stairs/

/*
  Algorithm
  ->It is an application of dp based fibonacci numbers
  ->Array of size two goes on adding up sum of results of previous two indexes
*/

class Solution {
public:
    int climbStairs(int n) {
        int arr[2];

        arr[0] = 1;
        arr[1] = 1;

        for (int i = 2; i <= n; i++)
            arr[i % 2] = arr[0] + arr[1];   //arr[0] or arr[1] is updated in each iteration

        return arr[n % 2];
    }
};

/*
    Complexity analysis
    Time complexity: O(n).
    Space complexity: O(1).
*/