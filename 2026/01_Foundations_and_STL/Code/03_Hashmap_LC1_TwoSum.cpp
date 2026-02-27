/**
 * PROBLEM: LeetCode 1 - Two Sum
 * ORDER: 03
 * ATOMIC TOPIC: Hashmap Lookup
 * 
 * DESCRIPTION:
 * Given an array of integers nums and an integer target, return indices of the two numbers 
 * such that they add up to target. You may assume each input would have exactly one solution.
 * 
 * CONSTRAINTS:
 * - 2 <= nums.length <= 10^4
 * - -10^9 <= nums[i] <= 10^9
 * - -10^9 <= target <= 10^9
 * 
 * GOAL:
 * Solve in O(N) time using std::unordered_map.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // TODO: Implement O(N) lookup logic
        return {};
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> res1 = sol.twoSum(nums1, target1);
    cout << "Test 1: [" << res1[0] << ", " << res1[1] << "] (Expected: [0, 1])" << endl;

    // Test Case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> res2 = sol.twoSum(nums2, target2);
    cout << "Test 2: [" << res2[0] << ", " << res2[1] << "] (Expected: [1, 2])" << endl;

    return 0;
}
