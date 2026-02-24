#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        // Collect all unique characters in the string
        for (char c : s) {
            letters.insert(c);
        }
        
        int ans = 0;
        // Iterate over each unique character
        for (char letter : letters) {
            int i = -1;
            int j = 0;
            
            // Find the first and last occurrence of the character
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == letter) {
                    if (i == -1) {
                        i = k;  // First occurrence of the character
                    }
                    j = k;  // Update the last occurrence of the character
                }
            }
            
            // Collect all unique characters between the first and last occurrence of `letter`
            unordered_set<char> between;
            for (int k = i + 1; k < j; k++) {
                between.insert(s[k]);
            }
            
            // Add the number of unique characters between i and j to the result
            ans += between.size();
        }
        
        return ans;
    }
};

int main() {
    Solution solution;

    // Test cases
    string test1 = "aab";
    cout << "Test case 1 - Input: " << test1 << ", Palindromic subsequences count: " 
         << solution.countPalindromicSubsequence(test1) << endl;

    string test2 = "aabca";
    cout << "Test case 2 - Input: " << test2 << ", Palindromic subsequences count: " 
         << solution.countPalindromicSubsequence(test2) << endl;

    string test3 = "abcd";
    cout << "Test case 3 - Input: " << test3 << ", Palindromic subsequences count: " 
         << solution.countPalindromicSubsequence(test3) << endl;

    string test4 = "aaaa";
    cout << "Test case 4 - Input: " << test4 << ", Palindromic subsequences count: " 
         << solution.countPalindromicSubsequence(test4) << endl;

    string test5 = "a";
    cout << "Test case 5 - Input: " << test5 << ", Palindromic subsequences count: " 
         << solution.countPalindromicSubsequence(test5) << endl;

    return 0;
}
