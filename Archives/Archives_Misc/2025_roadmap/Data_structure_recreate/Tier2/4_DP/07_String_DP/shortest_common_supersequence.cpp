#include <bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // Build LCS dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Trace to build SCS from LCS table
    int i = n, j = m;
    string scs = "";

    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            scs += a[i-1];
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            scs += a[i-1];
            i--;
        } else {
            scs += b[j-1];
            j--;
        }
    }

    // Add remaining characters
    while (i > 0) scs += a[i-1], i--;
    while (j > 0) scs += b[j-1], j--;

    reverse(scs.begin(), scs.end());
    return scs;
}

int main() {
    string a = "brute", b = "groot";
    cout << "Shortest Common Supersequence: " 
         << shortestCommonSupersequence(a, b) << endl;
    return 0;
}
