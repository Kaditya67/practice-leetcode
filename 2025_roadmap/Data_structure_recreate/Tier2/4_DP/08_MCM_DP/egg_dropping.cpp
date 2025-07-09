#include <bits/stdc++.h>
using namespace std;

int eggDrop(int k, int n) {
    vector<vector<int>> dp(k+1, vector<int>(n+1, 0));

    // Base cases:
    // 1 egg → try all floors
    for (int i = 1; i <= n; i++)
        dp[1][i] = i;

    for (int eggs = 2; eggs <= k; eggs++) {
        for (int floors = 1; floors <= n; floors++) {
            dp[eggs][floors] = INT_MAX;
            for (int x = 1; x <= floors; x++) {
                int break_case = dp[eggs-1][x-1];
                int not_break_case = dp[eggs][floors - x];
                int attempts = 1 + max(break_case, not_break_case);
                dp[eggs][floors] = min(dp[eggs][floors], attempts);
            }
        }
    }

    return dp[k][n];
}

int main() {
    int eggs = 2, floors = 10;
    cout << "Minimum attempts with " << eggs << " eggs and "
         << floors << " floors: " << eggDrop(eggs, floors) << endl;
    return 0;
}
