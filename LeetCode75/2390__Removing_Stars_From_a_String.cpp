// Problem: https://leetcode.com/problems/removing-stars-from-a-string/
// Difficulty: Easy

// Method: Stack
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string res;
        for (char ch : s) {
            if (ch == '*') {
                if (!res.empty()) {
                    res.pop_back();
                }
            } else {
                res.push_back(ch);
            }
        }
        return res;
    }
};

// Second Approach : Simple loop
class Solution2 {
public:
    string removeStars(string s) {
        string res;
        int n = s.length();

        int count=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='*'){
                count++;
            }else if(count){
                count--;
            }else{
                res.push_back(s[i]);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main() {
    Solution s;
    Solution2 s2;
    cout << s.removeStars("leet**cod*e") << endl;
    cout << s2.removeStars("leet**cod*e") << endl;
    return 0;
}
