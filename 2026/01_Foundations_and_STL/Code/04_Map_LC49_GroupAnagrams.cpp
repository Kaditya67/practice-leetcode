/**
 * PROBLEM: LeetCode 49 - Group Anagrams
 * ORDER: 04
 * ATOMIC TOPIC: Map with Complex Keys
 * 
 * DESCRIPTION:
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 * 
 * CONSTRAINTS:
 * - 1 <= strs.length <= 10^4
 * - 0 <= strs[i].length <= 100
 * - strs[i] consists of lowercase English letters.
 * 
 * GOAL:
 * Use std::unordered_map<string, vector<string>> where the key is the sorted string or frequency count.
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // TODO: Implement grouping logic
        return {};
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<string> strs1 = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res1 = sol.groupAnagrams(strs1);
    cout << "Test 1: Grouped Anagrams Count: " << res1.size() << " (Expected: 3)" << endl;

    return 0;
}
