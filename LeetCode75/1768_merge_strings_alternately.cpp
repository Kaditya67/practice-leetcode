// Problem link: https://leetcode.com/problems/merge-strings-alternately
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        string res = "";
        int n = word1.size();
        int m = word2.size();
        
        // merge the strings alternately
        while (i < n && j < m) {
            res += word1[i++];
            res += word2[j++];
        }
        
        // append the remaining characters
        if (i != n)
            res += word1.substr(i, n);
        if (j != m)
            res += word2.substr(j, m);
        
        return res;
    }
};

int main() {
    Solution s;
    cout << s.mergeAlternately("abc", "pqr") << endl;
    return 0;
}

