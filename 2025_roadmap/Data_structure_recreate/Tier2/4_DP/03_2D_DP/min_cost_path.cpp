#include <bits/stdc++.h>
using namespace std;

// int minPathSum(vector<vector<int>>& grid) {
//     int m = grid.size(), n = grid[0].size();
//     vector<vector<int>> dp(m, vector<int>(n));

//     dp[0][0] = grid[0][0];

//     // Fill first row
//     for (int j = 1; j < n; j++)
//         dp[0][j] = dp[0][j-1] + grid[0][j];

//     // Fill first column
//     for (int i = 1; i < m; i++)
//         dp[i][0] = dp[i-1][0] + grid[i][0];

//     // Fill rest
//     for (int i = 1; i < m; i++) {
//         for (int j = 1; j < n; j++) {
//             dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
//         }
//     }

//     return dp[m-1][n-1];
// }

// Space Optimization (2D → 1D)
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> dp(n, 0);

    for (int i = 0; i < m; i++) {
        vector<int> curr(n);
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) curr[j] = grid[0][0];
            else {
                int up = (i > 0) ? dp[j] : INT_MAX;
                int left = (j > 0) ? curr[j-1] : INT_MAX;
                curr[j] = grid[i][j] + min(up, left);
            }
        }
        dp = curr;
    }

    return dp[n-1];
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Min Cost: " << minPathSum(grid) << endl;
    return 0;
}
