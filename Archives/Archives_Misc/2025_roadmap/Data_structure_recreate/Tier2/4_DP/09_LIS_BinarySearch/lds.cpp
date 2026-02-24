#include <bits/stdc++.h>
using namespace std;

int lengthOfLDS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);  // dp[i] = length of LDS ending at index i

    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] < nums[j]) // Decreasing condition
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}

int main() {
    vector<int> nums = {9, 4, 3, 2, 5, 4, 3, 2};
    cout << "Length of LDS: " << lengthOfLDS(nums) << endl;
    return 0;
}
