#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int countWays(int i, int j, bool isTrue, string& expr, vector<vector<vector<int>>>& dp) {
    if (i > j) return 0;
    if (i == j) {
        if (isTrue)
            return expr[i] == 'T';
        else
            return expr[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    int ways = 0;
    for (int k = i + 1; k < j; k += 2) {
        char op = expr[k];

        int lt = countWays(i, k - 1, true, expr, dp);
        int lf = countWays(i, k - 1, false, expr, dp);
        int rt = countWays(k + 1, j, true, expr, dp);
        int rf = countWays(k + 1, j, false, expr, dp);

        if (op == '&') {
            if (isTrue) ways += lt * rt;
            else        ways += lt * rf + lf * rt + lf * rf;
        } else if (op == '|') {
            if (isTrue) ways += lt * rt + lt * rf + lf * rt;
            else        ways += lf * rf;
        } else if (op == '^') {
            if (isTrue) ways += lt * rf + lf * rt;
            else        ways += lt * rt + lf * rf;
        }

        ways %= MOD;
    }

    return dp[i][j][isTrue] = ways;
}

int countParenthToTrue(string expr) {
    int n = expr.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return countWays(0, n - 1, true, expr, dp);
}

int main() {
    string expr = "T|F&T^T";
    cout << "Ways to parenthesize to True: " << countParenthToTrue(expr) << endl;
    return 0;
}
