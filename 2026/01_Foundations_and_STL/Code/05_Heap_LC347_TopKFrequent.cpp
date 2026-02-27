/**
 * PROBLEM: LeetCode 347 - Top K Frequent Elements
 * ORDER: 05
 * ATOMIC TOPIC: Map + Priority Queue
 * 
 * DESCRIPTION:
 * Given an integer array nums and an integer k, return the k most frequent elements.
 * 
 * CONSTRAINTS:
 * - 1 <= nums.length <= 10^5
 * - k is in the range [1, the number of unique elements in the array].
 * 
 * GOAL:
 * Solve in better than O(N log N) using a hash map and a min-heap (priority_queue).
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // TODO: Implement Map + PQ logic
        return {};
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    vector<int> res1 = sol.topKFrequent(nums1, k1);
    cout << "Test 1: [";
    for(int n : res1) cout << n << " ";
    cout << "] (Expected: [1, 2])" << endl;

    return 0;
}
