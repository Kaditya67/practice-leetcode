/**
 * Problem: LeetCode 217 - Contains Duplicate
 * Atomic Topic: STL Set / Unordered Set
 * 
 * Target Accuracy: 70%+ First-Try
 * 
 * Documentation Requirements:
 * 1. Time Complexity: O(N) average, as we traverse the array once and hash set operations are O(1) average.
 * 2. Space Complexity: O(N) to store up to N elements in the hash set.
 * 3. Edge Cases Considered:
 *    - Empty array (false)
 *    - All unique elements (false)
 *    - All same elements (true)
 *    - Minimum size (1)
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.find(num) != seen.end()) return true;
            seen.insert(num);
        }
        return false;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    vector<int> test1 = {1, 2, 3, 1};
    vector<int> test2 = {1, 2, 3, 4};
    cout << "Test 1 [1,2,3,1]: " << sol.containsDuplicate(test1) << " (Expected: true)" << endl;
    cout << "Test 2 [1,2,3,4]: " << sol.containsDuplicate(test2) << " (Expected: false)" << endl;
    return 0;
}
