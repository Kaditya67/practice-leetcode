// Problem: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
// Difficulty: Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == 0) zeroCount++;

            // Shrink the window until we have at most 1 zero
            while (zeroCount > 1) {
                if (nums[i] == 0) zeroCount--;
                i++;
            }

            maxLen = max(maxLen, j - i);
        }

        return maxLen;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,0,1};
    cout << s.longestSubarray(nums) << endl; // 3
    return 0;
}
