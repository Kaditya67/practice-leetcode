#include <bits/stdc++.h>
using namespace std;

int editDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // Base case: converting to/from empty string
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    // Fill table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min({
                    dp[i-1][j],    // delete
                    dp[i][j-1],    // insert
                    dp[i-1][j-1]   // replace
                });
        }
    }

    return dp[n][m];
}

int main() {
    string w1 = "intention", w2 = "execution";
    cout << "Edit Distance: " << editDistance(w1, w2) << endl;
    return 0;
}
