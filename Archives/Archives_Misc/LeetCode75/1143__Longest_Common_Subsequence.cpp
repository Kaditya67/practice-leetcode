// Problem: https://leetcode.com/problems/longest-common-subsequence/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

// Recursive + memoization approach
// Time Complexity: O(m*n), Space Complexity: O(m*n) for memoization
class Solution {
public:
    int solve(string& s1, string& s2, int i, int j, int m, int n, vector<vector<int>>& t) {
        if (i >= m || j >= n) return 0;

        if (t[i][j] != -1) return t[i][j];   
        
        if (s1[i] == s2[j]) {
            t[i][j] = 1 + solve(s1, s2, i + 1, j + 1, m, n, t);
        } else {
            t[i][j] = max(
                solve(s1, s2, i, j + 1, m, n, t),
                solve(s1, s2, i + 1, j, m, n, t)
            );
        }

        return t[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> t(m + 1, vector<int>(n + 1, -1));   
        return solve(text1, text2, 0, 0, m, n, t);
    }
};

// Bottom-up DP approach
// Time Complexity: O(m*n), Space Complexity: O(m*n)
class Solution2 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> t(m + 1, vector<int>(n + 1, 0)); // initialized with 0

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        return t[m][n];
    }
};

int main() {
    Solution sol1;
    Solution2 sol2;

    string text1 = "abcde";
    string text2 = "ace";

    cout << "Recursive + Memoization approach: " << sol1.longestCommonSubsequence(text1, text2) << endl;
    cout << "Bottom-up DP approach: " << sol2.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}

