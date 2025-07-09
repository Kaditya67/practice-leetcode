#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    int INF = 1e9;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (int coin : coins) {
        for (int amt = coin; amt <= amount; amt++) {
            if (dp[amt - coin] != INF)
                dp[amt] = min(dp[amt], 1 + dp[amt - coin]);
        }
    }

    return dp[amount] == INF ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Min Coins Needed: " << minCoins(coins, amount) << endl;
    return 0;
}
