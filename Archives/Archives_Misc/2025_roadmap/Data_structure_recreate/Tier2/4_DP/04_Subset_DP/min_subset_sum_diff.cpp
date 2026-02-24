#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDiff(vector<int>& arr) {
    int n = arr.size();
    int total = accumulate(arr.begin(), arr.end(), 0);

    vector<vector<bool>> dp(n, vector<bool>(total + 1, false));

    // Base case
    for (int i = 0; i < n; i++) dp[i][0] = true;
    if (arr[0] <= total) dp[0][arr[0]] = true;

    // Fill DP table
    for (int i = 1; i < n; i++) {
        for (int t = 1; t <= total; t++) {
            bool skip = dp[i-1][t];
            bool take = (arr[i] <= t) ? dp[i-1][t - arr[i]] : false;
            dp[i][t] = skip || take;
        }
    }

    // Find the largest subset sum ≤ total/2
    int minDiff = INT_MAX;
    for (int s1 = 0; s1 <= total / 2; s1++) {
        if (dp[n-1][s1]) {
            int s2 = total - s1;
            minDiff = min(minDiff, abs(s2 - s1));
        }
    }

    return minDiff;
}

int main() {
    vector<int> arr = {1, 2, 3, 9};
    cout << "Minimum subset sum difference: "
         << minSubsetSumDiff(arr) << endl;
    return 0;
}
