#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i = 0;
        int patch = 0;
        long maxReach = 0;
        while (maxReach < n) {
            if (i < nums.size() && nums[i] <= maxReach + 1) {  // Ensure we check the index bounds first
                maxReach += nums[i];
                i++;
            } else {
                patch++;
                maxReach += (maxReach + 1); // Add the smallest number that can extend the range
            }
        }
        return patch;
    }
};

int main() {
    vector<int> nums = {1, 3};
    int n = 6;
    Solution s;
    cout << s.minPatches(nums, n) << endl;
    return 0;
}
