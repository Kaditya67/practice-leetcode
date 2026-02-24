#include <bits/stdc++.h>
using namespace std;

int rodCutting(int n, vector<int>& price) {
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    // Lengths are 1 to n
    vector<int> length(n);
    for (int i = 0; i < n; i++) length[i] = i + 1;

    for (int i = 0; i < n; i++) {
        for (int len = 0; len <= n; len++) {
            int take = (length[i] <= len) ? price[i] + dp[i][len - length[i]] : 0;
            int skip = (i > 0) ? dp[i - 1][len] : 0;
            dp[i][len] = max(take, skip);
        }
    }

    return dp[n - 1][n];
}

int main() {
    vector<int> price = {2, 5, 7, 8, 10}; // For lengths 1 to 5
    int n = 5;
    cout << "Max profit from rod cutting: " << rodCutting(n, price) << endl;
    return 0;
}
