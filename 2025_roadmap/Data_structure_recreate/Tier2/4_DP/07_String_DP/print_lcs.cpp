#include <bits/stdc++.h>
using namespace std;

string getLCS(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // Step 1: Build DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Step 2: Trace back to get the actual LCS
    int i = n, j = m;
    string lcs = "";
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            lcs += a[i-1];
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string s1 = "abcde", s2 = "ace";
    cout << "LCS: " << getLCS(s1, s2) << endl;
    return 0;
}
