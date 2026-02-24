#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string& s, int i, int j) {
    while (i < j)
        if (s[i++] != s[j--]) return false;
    return true;
}

int minCuts(int i, int n, string& s, vector<int>& dp) {
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];

    int minCost = INT_MAX;
    for (int j = i; j < n; j++) {
        if (isPalindrome(s, i, j)) {
            int cost = 1 + minCuts(j + 1, n, s, dp);
            minCost = min(minCost, cost);
        }
    }

    return dp[i] = minCost;
}

int minPalindromeCuts(string s) {
    int n = s.size();
    vector<int> dp(n, -1);
    return minCuts(0, n, s, dp) - 1; // subtract 1 because last cut is extra
}

int main() {
    string s = "aab";
    cout << "Minimum cuts for palindrome partitioning: "
         << minPalindromeCuts(s) << endl;
    return 0;
}
