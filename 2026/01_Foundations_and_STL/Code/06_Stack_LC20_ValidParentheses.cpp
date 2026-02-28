/**
 * Problem: LeetCode 20 - Valid Parentheses
 * CodeChef: COMPILER (Compilers and Parsers) - Stack
 * ORDER: 06
 * ATOMIC TOPIC: Stack LIFO Logic
 *
 * DESCRIPTION:
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * CONSTRAINTS:
 * - 1 <= s.length <= 10^4
 * - s consists of parentheses only '()[]{}'.
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    // TODO: Implement Stack logic
    stack<char> parentheses;

    for (char ch : s) {
      if (ch == '(' || ch == '{' || ch == '[') {
        parentheses.push(ch);
      } else {
        if (parentheses.empty())
          return false;
        char top = parentheses.top();
        if ((top == '(' && ch == ')') || (top == '{' && ch == '}') ||
            (top == '[' && ch == ']')) {
          parentheses.pop();
        } else {
          return false;
        }
      }
    }
    return parentheses.empty();
  }
};

int main() {
  Solution sol;

  // Test Case 1
  string s1 = "()[]{}";
  cout << "Test 1: " << boolalpha << sol.isValid(s1) << " (Expected: true)"
       << endl;

  // Test Case 2
  string s2 = "(]";
  cout << "Test 2: " << sol.isValid(s2) << " (Expected: false)" << endl;

  return 0;
}
