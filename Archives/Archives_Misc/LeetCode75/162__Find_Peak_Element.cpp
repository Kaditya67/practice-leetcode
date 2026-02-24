// Problem: https://leetcode.com/problems/find-peak-element/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[mid + 1]) {
                l = mid + 1; // Move right
            } else {
                r = mid; // Move left
            }
        }

        return l;
    }
};


int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.findPeakElement(nums) << endl;
    return 0;
}
