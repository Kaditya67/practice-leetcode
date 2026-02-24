// Problem: https://leetcode.com/problems/house-robber/
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

// Top-down DP approach with memoization
// Time Complexity: O(n)
class Solution {
public:
    int solve(vector<int> &nums, int idx, int n, vector<int>& dp){
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];

        int steal = nums[idx] + solve(nums, idx + 2, n, dp);
        int skip = solve(nums, idx + 1, n, dp);

        return dp[idx] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1); 
        return solve(nums, 0, n, dp);
    }
};


// Bottom-up DP approach
// Time Complexity: O(n)
class Solution2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1); 
        // dp[i]    // Max money till i house
        dp[0] = 0;      // No house - No money
        dp[1] = nums[0];    // 1 house
        for(int i=2;i<=n;++i){
            int skip = dp[i-1];
            int steal = nums[i-1]+dp[i-2];
            dp[i] = max(steal,skip);
        }
        return dp[n];
    }
};


int main() {
    Solution s;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << s.rob(nums) << endl;
    return 0;
}
