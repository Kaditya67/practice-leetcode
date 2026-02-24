#include <bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> lis(n, 1), lds(n, 1);

    // LIS from left to right
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (nums[i] > nums[j])
                lis[i] = max(lis[i], lis[j] + 1);
    }

    // LDS from right to left
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--)
            if (nums[i] > nums[j])
                lds[i] = max(lds[i], lds[j] + 1);
    }

    int maxBitonic = 0;
    for (int i = 0; i < n; i++)
        maxBitonic = max(maxBitonic, lis[i] + lds[i] - 1);

    return maxBitonic;
}

int main() {
    vector<int> nums = {1, 11, 2, 10, 4, 5, 2, 1};
    cout << "Length of Longest Bitonic Subsequence: "
         << longestBitonicSubsequence(nums) << endl;
    return 0;
}
