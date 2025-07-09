#include <bits/stdc++.h>
using namespace std;

// 🧠 Space-Optimized Fibonacci approach
int climbStairsOptimized(int n) {
    if (n <= 1) return 1;
    int prev1 = 1, prev2 = 1;
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

// 🧠 Tabulation (Bottom-Up DP)
int climbStairsTabu(int n) {
    if (n <= 1) return 1;
    vector<int> dp(n+1);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}

// Memoization
int solve(int n, vector<int>& dp) {
    if (n <= 1) return 1; // only 1 way to stay or reach 1st step
    if (dp[n] != -1) return dp[n];
    return dp[n] = solve(n-1, dp) + solve(n-2, dp);
}

int main() {
    int n;
    cin >> n;

    cout << "Ways to climb (Tabulation): " << climbStairsTabu(n) << endl;
    cout << "Ways to climb (Optimized): " << climbStairsOptimized(n) << endl;
    vector<int> dp(n+1, -1);
    cout << "Ways to climb (Memoization): " << solve(n, dp) << endl;

    return 0;
}
