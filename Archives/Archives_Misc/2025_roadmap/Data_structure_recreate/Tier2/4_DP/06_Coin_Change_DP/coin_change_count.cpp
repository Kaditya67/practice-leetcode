#include <bits/stdc++.h>
using namespace std;

// int countWays(vector<int>& coins, int amount) {
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

//     // Base Case: fill first row
//     for (int t = 0; t <= amount; t++) {
//         dp[0][t] = (t % coins[0] == 0) ? 1 : 0;
//     }

//     for (int i = 1; i < n; i++) {
//         for (int t = 0; t <= amount; t++) {
//             int skip = dp[i-1][t];
//             int take = (coins[i] <= t) ? dp[i][t - coins[i]] : 0;
//             dp[i][t] = skip + take;
//         }
//     }

//     return dp[n-1][amount];
// }

// Space Optimization (2D → 1D DP)
int countWays(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int t = coin; t <= amount; t++) {
            dp[t] += dp[t - coin];
        }
    }

    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << "Total Ways: " << countWays(coins, amount) << endl;
    return 0;
}
