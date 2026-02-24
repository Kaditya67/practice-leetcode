#include <bits/stdc++.h>
using namespace std;

int countSubsets(vector<int>& arr, int sum) {
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for (int num : arr) {
        for (int t = sum; t >= num; t--) {
            dp[t] += dp[t - num];
        }
    }
    return dp[sum];
}

int countPartitionsWithDiff(vector<int>& arr, int diff) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if ((totalSum + diff) % 2 != 0 || totalSum < diff)
        return 0;

    int target = (totalSum + diff) / 2;
    return countSubsets(arr, target);
}

int main() {
    vector<int> arr = {1, 1, 2, 3};
    int diff = 1;
    cout << "Partitions with difference " << diff << ": "
         << countPartitionsWithDiff(arr, diff) << endl;
    return 0;
}
