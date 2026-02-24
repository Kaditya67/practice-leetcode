#include <bits/stdc++.h>
using namespace std;

// int countSubsets(vector<int>& arr, int target) {
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int>(target + 1, 0));

//     // base case
//     dp[0][0] = 1;
//     if (arr[0] <= target) dp[0][arr[0]]++;

//     for (int i = 1; i < n; i++) {
//         for (int sum = 0; sum <= target; sum++) {
//             int skip = dp[i-1][sum];
//             int take = (arr[i] <= sum) ? dp[i-1][sum - arr[i]] : 0;
//             dp[i][sum] = skip + take;
//         }
//     }

//     return dp[n-1][target];
// }

// Space Optimized (1D DP)
int countSubsets(vector<int>& arr, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int num : arr) {
        for (int sum = target; sum >= num; sum--) {
            dp[sum] += dp[sum - num];
        }
    }

    return dp[target];
}

int main() {
    vector<int> arr = {1, 2, 3, 3};
    int target = 6;
    cout << "Count of subsets with sum " << target << ": "
         << countSubsets(arr, target) << endl;
    return 0;
}
