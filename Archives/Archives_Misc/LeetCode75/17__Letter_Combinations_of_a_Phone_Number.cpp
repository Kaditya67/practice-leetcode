// Problem: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int idx, string& s, string& temp, vector<string>& res,unordered_map<char,string>& mp){
        if(idx>=s.length()){
            res.push_back(temp);
        }

        char ch = s[idx];
        string str = mp[ch];
        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]); // Do
            solve(idx+1,s,temp,res,mp); // Explore
            temp.pop_back();    // Undo
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};

        unordered_map<char,string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> res;
        string temp = "";
        solve(0,digits,temp,res,mp);
        return res;
    }
};

int main(){
    Solution s;
    vector<string> res = s.letterCombinations("23");
    for(string str : res){
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
