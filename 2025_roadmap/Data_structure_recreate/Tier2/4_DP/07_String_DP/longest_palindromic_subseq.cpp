#include <bits/stdc++.h>
using namespace std;

int longestPalindromicSubsequence(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());

    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    // LCS(s, rev)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == rev[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][n];
}

int main() {
    string s = "bbabcbcab";
    cout << "Longest Palindromic Subsequence length: "
         << longestPalindromicSubsequence(s) << endl;
    return 0;
}
