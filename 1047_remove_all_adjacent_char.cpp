#include<iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        // Iterate through each character in the string
        for (char ch : s) {
            // If the stack is not empty and the current character is equal to the character at the top of the stack
            if (!stk.empty() && stk.top() == ch) {
                // Remove the character from the stack
                stk.pop();
            } else {
                // Push the current character onto the stack
                stk.push(ch);
            }
        }
        // Construct the result string from the characters remaining in the stack
        string result;
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }
        return result;
    }
};

int main(){
    string s = "abbaca";
    Solution sol;
    cout << sol.removeDuplicates(s) << endl;
    return 0;
}