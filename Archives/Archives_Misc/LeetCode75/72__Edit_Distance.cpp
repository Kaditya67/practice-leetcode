// Problem: https://leetcode.com/problems/edit-distance/
// Difficulty: Hard

#include <bits/stdc++.h>
using namespace std;

// Recursive + memoization approach
// Time Complexity: O(m*n), Space Complexity: O(m*n) for memoization
class Solution {
public:
    int dp[501][501];

    int solve(string &a, string &b, int i, int j) {
        if (i == a.size()) return b.size() - j;  // insert remaining b[j:]
        if (j == b.size()) return a.size() - i;  // delete remaining a[i:]

        if (dp[i][j] != -1) return dp[i][j];

        if (a[i] == b[j]) {
            return dp[i][j] = solve(a, b, i + 1, j + 1);  // chars match
        }

        int insertOp = 1 + solve(a, b, i, j + 1);
        int deleteOp = 1 + solve(a, b, i + 1, j);
        int replaceOp = 1 + solve(a, b, i + 1, j + 1);

        return dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, 0, 0);
    }
};

// Bottom-up DP approach
// Time Complexity: O(m*n), Space Complexity: O(m*n)
class Solution2 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // Base cases
        for (int i = 0; i <= m; ++i) dp[i][n] = m - i; // delete rest
        for (int j = 0; j <= n; ++j) dp[m][j] = n - j; // insert rest

        // Bottom-up fill
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int insertOp = 1 + dp[i][j + 1];
                    int deleteOp = 1 + dp[i + 1][j];
                    int replaceOp = 1 + dp[i + 1][j + 1];
                    dp[i][j] = min({insertOp, deleteOp, replaceOp});
                }
            }
        }

        return dp[0][0];
    }
};

// Space-optimized DP approach
// Time Complexity: O(m*n), Space Complexity: O(n)
class Solution3 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> prev(n + 1), curr(n + 1);

        // Base case: converting empty word1 to word2
        for (int j = 0; j <= n; ++j) prev[j] = n - j;

        for (int i = m - 1; i >= 0; --i) {
            curr[n] = m - i;
            for (int j = n - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    curr[j] = prev[j + 1];
                } else {
                    int insertOp = 1 + curr[j + 1];
                    int deleteOp = 1 + prev[j];
                    int replaceOp = 1 + prev[j + 1];
                    curr[j] = min({insertOp, deleteOp, replaceOp});
                }
            }
            prev = curr;
        }

        return curr[0];
    }
};


int main() {
    Solution s;
    cout << s.minDistance("horse", "ros") << endl;  // Output: 3
    return 0;
}