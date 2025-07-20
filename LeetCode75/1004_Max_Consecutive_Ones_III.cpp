// Problem: https://leetcode.com/problems/max-consecutive-ones-iii/
// Difficulty: Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int zeroCount = 0;
        int maxCount = 0;

        while (j < n) {
            if (nums[j] == 0) {
                zeroCount++;
            }

            while (zeroCount > k) {
                if (nums[i] == 0) {
                    zeroCount--;
                }
                i++;
            }

            maxCount = max(maxCount, j - i + 1);
            j++;
        }

        return maxCount;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1};
    int k = 2;
    cout << sol.longestOnes(nums, k) << endl; // Example usage
    return 0;
}

