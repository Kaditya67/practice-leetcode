// Problem: https://leetcode.com/problems/maximum-average-subarray-i/
// Difficulty: Medium

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double res = sum;

        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            res = max(res, sum);
        }

        return res / k;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    cout << s.findMaxAverage(nums,k) << endl;
    return 0;
}
