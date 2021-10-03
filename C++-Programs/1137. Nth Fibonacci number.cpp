//Submitted by Harivams Sai Gudalwar (https://github.com/harivams-sai)
// Question link: https://leetcode.com/problems/n-th-tribonacci-number/

/*
  Algorithm
  ->Dp way of obtaining fibonacci numbers
  ->Array of size three adds sum of results of previous three indexes.
*/

class Solution {
public:
    int tribonacci(int n) {
        int arr[3];

        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        for (int i = 3; i <= n; i++)
            arr[i % 3] = arr[0] + arr[1] + arr[2];

        return arr[n % 3];
    }
};

/*
    Complexity analysis
    Time complexity: O(n).
    Space complexity: O(1).
*/