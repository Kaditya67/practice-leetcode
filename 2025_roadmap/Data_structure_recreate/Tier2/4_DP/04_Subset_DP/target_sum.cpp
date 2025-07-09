#include <bits/stdc++.h>
using namespace std;

int countSubsetsWithSum(vector<int>& nums, int sum) {
    int n = nums.size();
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for (int num : nums) {
        for (int t = sum; t >= num; t--) {
            dp[t] += dp[t - num];
        }
    }
    return dp[sum];
}

int findTargetSumWays(vector<int>& nums, int target) {
    int total = accumulate(nums.begin(), nums.end(), 0);

    if ((target + total) % 2 != 0 || total < abs(target))
        return 0;

    int subsetSum = (target + total) / 2;
    return countSubsetsWithSum(nums, subsetSum);
}

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << "Ways to assign +/- to get target: "
         << findTargetSumWays(nums, target) << endl;
    return 0;
}
