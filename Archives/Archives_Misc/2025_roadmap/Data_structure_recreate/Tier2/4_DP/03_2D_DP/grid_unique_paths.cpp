#include <bits/stdc++.h>
using namespace std;

// int uniquePaths(int m, int n) {
//     vector<vector<int>> dp(m, vector<int>(n, 1)); // base case filled

//     for (int i = 1; i < m; i++) {
//         for (int j = 1; j < n; j++) {
//             dp[i][j] = dp[i-1][j] + dp[i][j-1]; // from top + from left
//         }
//     }

//     return dp[m-1][n-1];
// }

// Space Optimization (2D → 1D)
int uniquePaths(int m, int n) {
    vector<int> prev(n, 1);

    for (int i = 1; i < m; i++) {
        vector<int> curr(n, 1);
        for (int j = 1; j < n; j++)
            curr[j] = curr[j-1] + prev[j];
        prev = curr;
    }

    return prev[n-1];
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << "Unique Paths: " << uniquePaths(m, n) << endl;
    return 0;
}
