#include <bits/stdc++.h>
using namespace std;

// int rob(vector<int>& nums) {
//     int n = nums.size();
//     if (n == 0) return 0;
//     if (n == 1) return nums[0];

//     vector<int> dp(n);
//     dp[0] = nums[0];
//     dp[1] = max(nums[0], nums[1]);

//     for (int i = 2; i < n; i++)
//         dp[i] = max(dp[i-1], nums[i] + dp[i-2]);

//     return dp[n-1];
// }

// Space Optimized Version
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int prev1 = nums[0], prev2 = 0;

    for (int i = 1; i < n; i++) {
        int take = nums[i] + prev2;
        int skip = prev1;
        int curr = max(take, skip);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}


int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Max loot: " << rob(nums) << endl;
    return 0;
}
