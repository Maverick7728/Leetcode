// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed, 
// the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.



class Solution {
public:
    vector<int> memo;
    int solve(vector<int>& nums, int index) {
        if (index >= nums.size()) {
            return 0;
        }
        if (memo[index] != -1) {
            return memo[index];
        }
        int include = nums[index] + solve(nums, index + 2);
        int exclude = solve(nums, index + 1);
        int ans = max(include, exclude);
        memo[index] = ans;
        return ans;
    }
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        int ans = solve(nums, 0);
        return ans;
    }
};

 