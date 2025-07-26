// Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

// Recursive + memoization approach
// Time Complexity: O(n), Space Complexity: O(n) for memoization
class Solution {
public:
    int dp[50001][2];  // memo table: dp[day][holding]

    int solve(vector<int>& prices, int i, bool holding, int fee) {
        if (i == prices.size()) return 0;
        if (dp[i][holding] != -1) return dp[i][holding];

        int doNothing = solve(prices, i + 1, holding, fee);
        int doSomething;

        if (holding) {
            // Option to sell
            doSomething = prices[i] - fee + solve(prices, i + 1, 0, fee);
        } else {
            // Option to buy
            doSomething = -prices[i] + solve(prices, i + 1, 1, fee);
        }

        return dp[i][holding] = max(doNothing, doSomething);
    }

    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 0, fee); // start on day 0, not holding
    }
};

// Bottom-up DP approach
class Solution2 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // dp[i][0] = max profit on day i with no stock
        // dp[i][1] = max profit on day i with stock

        for (int i = n - 1; i >= 0; i--) {
            // Not holding
            dp[i][0] = max(dp[i + 1][0], -prices[i] + dp[i + 1][1]);
            // Holding
            dp[i][1] = max(dp[i + 1][1], prices[i] - fee + dp[i + 1][0]);
        }

        return dp[0][0]; // start from day 0 with no stock
    }
};


// Space-optimized DP approach
class Solution3 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            cash = max(cash, hold + prices[i] - fee); // sell
            hold = max(hold, cash - prices[i]);       // buy
        }

        return cash;
    }
};


int main() {
    Solution s;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << s.maxProfit(prices, fee) << endl;  // Output: 8
    return 0;
}
