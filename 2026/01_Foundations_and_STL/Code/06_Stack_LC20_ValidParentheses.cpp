/**
 * PROBLEM: LeetCode 20 - Valid Parentheses
 * ORDER: 06
 * ATOMIC TOPIC: Stack LIFO Logic
 * 
 * DESCRIPTION:
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * 
 * CONSTRAINTS:
 * - 1 <= s.length <= 10^4
 * - s consists of parentheses only '()[]{}'.
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // TODO: Implement Stack logic
        return false;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "()[]{}";
    cout << "Test 1: " << boolalpha << sol.isValid(s1) << " (Expected: true)" << endl;

    // Test Case 2
    string s2 = "(]";
    cout << "Test 2: " << sol.isValid(s2) << " (Expected: false)" << endl;

    return 0;
}
