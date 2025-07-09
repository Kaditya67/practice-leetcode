#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Base case
    if (grid[0][0] == 0)
        dp[0][0] = 1;

    // Fill first row
    for (int j = 1; j < n; j++)
        if (grid[0][j] == 0) dp[0][j] = dp[0][j-1];

    // Fill first column
    for (int i = 1; i < m; i++)
        if (grid[i][0] == 0) dp[i][0] = dp[i-1][0];

    // Fill the rest
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << "Unique Paths with Obstacles: " << uniquePathsWithObstacles(grid) << endl;
    return 0;
}
