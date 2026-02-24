// Problem: https://leetcode.com/problems/string-compression/
// Difficulty: Medium
// Concept: Two Pointers

#include <iostream>
#include <vector>

using namespace std;

//! Note: You Have to Modify the Input Array
class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0; // write pointer
        int i = 0;     // read pointer

        while (i < chars.size()) {
            char currentChar = chars[i];
            int count = 0;

            while (i < chars.size() && chars[i] == currentChar) {
                i++;
                count++;
            }

            chars[index++] = currentChar; 

            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[index++] = c;  
                }
            }
        }

        return index;
    }
};


int main() {
    Solution s;
    vector<char> chars = {'a','a','b','b','c','c','c'};
    cout << s.compress(chars) << endl;
    return 0;
}