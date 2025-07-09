#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;
    int target = sum / 2;

    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(target+1, false));

    for (int i = 0; i < n; i++) dp[i][0] = true;
    if (nums[0] <= target) dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int t = 1; t <= target; t++) {
            bool skip = dp[i-1][t];
            bool take = (nums[i] <= t) ? dp[i-1][t - nums[i]] : false;
            dp[i][t] = skip || take;
        }
    }

    return dp[n-1][target];
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout << (canPartition(nums) ? "Can Partition" : "Cannot Partition") << endl;
    return 0;
}
