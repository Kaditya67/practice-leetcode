// Problem: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/
// Difficulty: Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(nums[0]);

        // Step 1: Remove consecutive duplicates
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != arr.back()) {
                arr.push_back(nums[i]);
            }
        }

        // Step 2: Count hills and valleys
        int count = 0;
        for (int i = 1; i < arr.size() - 1; ++i) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                // Hill
                count++;
            } else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                // Valley
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 4, 1, 1, 6, 5};
    int count = solution.countHillValley(nums);
    cout << "Number of hills and valleys: " << count << endl;
    return 0;
}

