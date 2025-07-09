#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>& balloons) {
    int n = balloons.size();
    vector<int> nums(n + 2, 1);
    for (int i = 0; i < n; i++)
        nums[i + 1] = balloons[i];
    n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = max(dp[i][j],
                               nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    vector<int> nums = {3, 1, 5, 8};
    cout << "Max coins from bursting balloons: " << maxCoins(nums) << endl;
    return 0;
}
