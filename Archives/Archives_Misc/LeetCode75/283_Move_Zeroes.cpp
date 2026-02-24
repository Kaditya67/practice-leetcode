// Problem: https://leetcode.com/problems/move-zeroes/
// Difficulty: Easy

// Concept: Find the Nonzero and keep placing it in front using index and Keep moving until we reach the end
// Fill the rest of the values with 0 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if (nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }
        while (index < n) {
            nums[index++] = 0;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
