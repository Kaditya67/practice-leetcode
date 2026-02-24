// Problem: https://leetcode.com/problems/reverse-words-in-a-string/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.length();
        for(int i=0;i<n;i++){
            while(i < n && s[i]==' ') i++;      // Removing Trailing Spaces

            string temp = "";
            while(i < n && s[i] != ' ') {
                temp+=s[i];
                i++;
            }

            if (!temp.empty()) words.push_back(temp);
        }

        string res="";
        int N = words.size();
        for(int i=N-1;i>=0;i--){
            res += words[i];
            if(i!=0) res+=" ";
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.reverseWords("the sky is blue") << endl; // "blue is sky the"
    return 0;
}
