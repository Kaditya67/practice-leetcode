// Problem: https://leetcode.com/problems/determine-if-two-strings-are-close/
// Difficulty: Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if(n!=m) return false;

        vector<int> v1(26,0);
        vector<int> v2(26,0);

        for(char ch:word1) v1[ch-'a']++;
        for(char ch:word2) v2[ch-'a']++;

        for(int i=0;i<26;i++){
            if((v1[i]==0 && v2[i]!=0) ||(v1[i]!=0 && v2[i]==0)) return false;
        }

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    string word1 = "abc";
    string word2 = "bca";
    cout << boolalpha << s.closeStrings(word1, word2) << endl; // true
    return 0;
}