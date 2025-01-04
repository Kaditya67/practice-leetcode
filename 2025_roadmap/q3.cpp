#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        vector<int> dp(n, 1); // dp[i] stores the length of the longest subsequence ending at index i

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Compare the absolute difference of nums[i] with nums[j]
                if (abs(nums[i] - nums[j]) <= abs(nums[j] - nums[max(0, j - 1)])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {16, 6, 3};
    cout << "Example 1:" << endl;
    cout << "Input: nums = [16, 6, 3]" << endl;
    cout << "Output: " << solution.longestSubsequence(nums1) << endl;

    // Example 2
    vector<int> nums2 = {6, 5, 3, 4, 2, 1};
    cout << "\nExample 2:" << endl;
    cout << "Input: nums = [6, 5, 3, 4, 2, 1]" << endl;
    cout << "Output: " << solution.longestSubsequence(nums2) << endl;

    // Example 3
    vector<int> nums3 = {10, 20, 10, 19, 10, 20};
    cout << "\nExample 3:" << endl;
    cout << "Input: nums = [10, 20, 10, 19, 10, 20]" << endl;
    cout << "Output: " << solution.longestSubsequence(nums3) << endl;

    // Example 4
    vector<int> nums4 = {4, 5, 2, 6, 9};
    cout << "\nExample 4:" << endl;
    cout << "Input: nums = [4, 5, 2, 6, 9]" << endl;
    cout << "Output: " << solution.longestSubsequence(nums4) << endl;

    return 0;
}
