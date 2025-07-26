// Problem: https://leetcode.com/problems/single-number/
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

// Using XOR to find the single number
// Time Complexity: O(n), Space Complexity: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;  // XOR with each number
        }
        return result;
    }
};

// Using normal iteration
// Time Complexity: O(n), Space Complexity: O(n) for the hash map
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }
        for (const auto& pair : countMap) {
            if (pair.second == 1) {
                return pair.first;  // Return the number that appears only once
            }
        }
        return -1;  // Should not reach here if input is valid
    }
};


int main() {
    Solution s;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << s.singleNumber(nums) << endl;  // Output: 4
    return 0;
}

// Idea Behind: You can cancel out the same number by XORing it again and again.
//? Dry Run Example:
// nums = [4, 1, 2, 1, 2]

// result = 0
// result ^= 4 → result = 4        // Property: 0 ^ a = a
// result ^= 1 → result = 5        // Property: a ^ a = 0   // Cancels out ( Used Everywhere )
// result ^= 2 → result = 7
// result ^= 1 → result = 6
// result ^= 2 → result = 4 (Answer!)       // 4 was preserved, all others canceled out


//! XOR Properties Used:
//? Identity:
// a ^ 0 = a
// → Any number XORed with 0 gives the number itself.

//? Self-Canceling:
// a ^ a = 0
// → A number XORed with itself becomes 0.

//? Associative & Commutative:
// (a ^ b) ^ c = a ^ (b ^ c)
// and
// a ^ b = b ^ a
// → Order doesn't matter!