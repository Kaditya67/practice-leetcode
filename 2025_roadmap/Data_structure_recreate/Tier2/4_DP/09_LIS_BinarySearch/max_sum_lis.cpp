#include <bits/stdc++.h>
using namespace std;

int maxSumIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp = nums;  // base: single element's sum is itself
    int maxSum = nums[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], nums[i] + dp[j]);
        }
        maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {1, 101, 2, 3, 100, 4, 5};
    cout << "Max Sum of Increasing Subsequence: "
         << maxSumIncreasingSubsequence(nums) << endl;
    return 0;
}
