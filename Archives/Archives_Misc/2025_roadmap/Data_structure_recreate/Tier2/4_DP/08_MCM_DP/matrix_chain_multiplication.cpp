#include <bits/stdc++.h>
using namespace std;

int matrixChainMemo(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int minCost = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = matrixChainMemo(i, k, arr, dp) +
                   matrixChainMemo(k+1, j, arr, dp) +
                   arr[i-1] * arr[k] * arr[j];
        minCost = min(minCost, cost);
    }
    return dp[i][j] = minCost;
}

int matrixChainOrder(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return matrixChainMemo(1, n-1, arr, dp);
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 30};
    cout << "Minimum multiplications: "
         << matrixChainOrder(arr) << endl;
    return 0;
}
