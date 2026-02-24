#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(sum+1, false));

    // base cases
    for (int i = 0; i < n; i++) dp[i][0] = true;
    if (arr[0] <= sum) dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= sum; target++) {
            bool skip = dp[i-1][target];
            bool take = (arr[i] <= target) ? dp[i-1][target - arr[i]] : false;
            dp[i][target] = skip || take;
        }
    }

    return dp[n-1][sum];
}

int main() {
    vector<int> arr = {2, 3, 7, 8, 10};
    int sum = 11;
    cout << (isSubsetSum(arr, sum) ? "Yes" : "No") << endl;
    return 0;
}
