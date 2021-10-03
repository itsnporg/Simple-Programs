//Submitted by Harivams Sai Gudalwar (https://github.com/harivams-sai)
// Question link: https://leetcode.com/problems/jump-game/

/*
  Algorithm
  ->Find and update maximum reach in each iteration by max(max reach uptil now,reach by current index)
  ->if this_far (current max reach) equals or is greater than n-1, true is returned while also
    satisfying i<n and this_far<n-1.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int this_far = 0;
        int n = nums.size();
        for (int i = 0; i < n && i <= this_far && this_far < n - 1; ++i) {
            this_far = max(this_far, i + nums[i]);
            // cout<<i<<" "<<this_far<<"\n";
        }
        return this_far >= n - 1;
    }
};

/*
    Complexity analysis
    Time complexity: O(n).
    Constant space.
    Space complexity: O(1).
*/