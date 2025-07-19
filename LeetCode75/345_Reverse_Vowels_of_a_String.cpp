// Problem: https://leetcode.com/problems/reverse-vowels-of-a-string/
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char ch) {
        return (ch == 'A' || ch == 'a' || 
                ch == 'E' || ch == 'e' || 
                ch == 'I' || ch == 'i' || 
                ch == 'O' || ch == 'o' || 
                ch == 'U' || ch == 'u');
    }
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            if (!isVowel(s[i]) && !isVowel(s[j])) {
                i++;
                j--;
            } 
            else if (isVowel(s[i]) && !isVowel(s[j])) {
                j--;
            } 
            else if (!isVowel(s[i]) && isVowel(s[j])) {
                i++;
            } 
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};


int main() {
    Solution sol;
    string s = "IceCreAm";
    cout << sol.reverseVowels(s) << endl; // Output: holle
    return 0;
}

