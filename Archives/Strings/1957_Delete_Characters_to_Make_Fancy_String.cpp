#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     string makeFancyString(string s) {
//         int n = s.length();
//         string res;
//         res+=s[0];

//         int count=1;
//         int i = 1;
//         while(i<n){
//             while(count>=2 && s[i-1]==s[i] && i<n){
//                 i++;
//             }
//             if(i==n) break;
//             if(s[i-1]==s[i]) count++;
//             else{
//                 count=1;
//             }
//             res+=s[i];
//             i++;
//         }
//         return res;
//     }
// };

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string res;
        res += s[0];
        int count = 1;

        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            
            if (count < 3) {
                res += s[i];
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    string s1 = "leeetcode";
    string res = s.makeFancyString(s1);
    cout<<"Output: "<<res<<endl;
    return 0;
}
