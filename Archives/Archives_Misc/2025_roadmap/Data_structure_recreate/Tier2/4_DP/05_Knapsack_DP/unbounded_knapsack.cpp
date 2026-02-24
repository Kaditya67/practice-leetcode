#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n, vector<int>(W+1, 0));

    // Base case: pick as many of item 0 as possible
    for (int w = 0; w <= W; w++) {
        dp[0][w] = (w / wt[0]) * val[0];
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            int skip = dp[i-1][w];
            int take = (wt[i] <= w) ? val[i] + dp[i][w - wt[i]] : 0;
            dp[i][w] = max(skip, take);
        }
    }

    return dp[n-1][W];
}

int main() {
    vector<int> wt = {2, 3, 4};
    vector<int> val = {40, 50, 60};
    int W = 8;

    cout << "Max value: " << unboundedKnapsack(W, wt, val, wt.size()) << endl;
    return 0;
}
