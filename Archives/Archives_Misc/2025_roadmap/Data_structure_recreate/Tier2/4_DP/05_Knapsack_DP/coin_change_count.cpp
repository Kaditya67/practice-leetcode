#include <bits/stdc++.h>
using namespace std;

int countWays(vector<int>& coins, int sum) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    // Base case: 1 way to make sum=0 (use nothing)
    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int amt = 0; amt <= sum; amt++) {
            if (coins[i - 1] <= amt)
                dp[i][amt] = dp[i - 1][amt] + dp[i][amt - coins[i - 1]];
            else
                dp[i][amt] = dp[i - 1][amt];
        }
    }

    return dp[n][sum];
}

// vector<int> dp(sum+1, 0);
// dp[0] = 1;

// for (int coin : coins)
//     for (int amt = coin; amt <= sum; amt++)
//         dp[amt] += dp[amt - coin];

int main() {
    vector<int> coins = {1, 2, 3};
    int target = 4;
    cout << "Total ways to make " << target << ": "
         << countWays(coins, target) << endl;
    return 0;
}
