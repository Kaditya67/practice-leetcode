#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int>& coins, int target) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 1e9));

    // Base case: 0 target → 0 coins
    for (int i = 0; i < n; i++)
        dp[i][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int amt = 1; amt <= target; amt++) {
            int take = (coins[i] <= amt) ? 1 + dp[i][amt - coins[i]] : 1e9;
            int skip = (i > 0) ? dp[i - 1][amt] : 1e9;
            dp[i][amt] = min(take, skip);
        }
    }

    int ans = dp[n - 1][target];
    return (ans >= 1e9) ? -1 : ans;
}

// Optimize

// vector<int> dp(target + 1, 1e9);
// dp[0] = 0;

// for (int coin : coins) {
//     for (int amt = coin; amt <= target; amt++) {
//         dp[amt] = min(dp[amt], 1 + dp[amt - coin]);
//     }
// }


int main() {
    vector<int> coins = {1, 2, 5};
    int target = 11;
    cout << "Min coins to make " << target << ": "
         << minCoins(coins, target) << endl;
    return 0;
}
