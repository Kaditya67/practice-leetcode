#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        if(n < m) return false;
        vector<int> v(n,0);

        int count = 0;
        for (int i = 0; i < p.size(); i++) {
            size_t pos =-1;
            if(p[i] == '*') {
                count++;
                continue;
            }

            while(pos == -1 && v[pos]==1) {
                pos = s.find(p[i], pos+1);
            }
            if(pos != -1) {
                v[pos] = 1;
            }
        }

        int tempCount = 0;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if((prev == 0 && v[i] == 1) || (v[i] == 0 && prev == 1)) {
                tempCount++;
            }
            if(v[i] == 0) {
                prev = 0;
            }else{
                prev = 1;
            }
            if(tempCount > count) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Example 1
    string s1 = "leetcode", p1 = "ee*e";
    cout << "Example 1:" << endl;
    cout << "Input: s = \"leetcode\", p = \"ee*e\"" << endl;
    cout << "Output: " << (solution.hasMatch(s1, p1) ? "true" : "false") << endl;

    // Example 2
    string s2 = "car", p2 = "c*v";
    cout << "\nExample 2:" << endl;
    cout << "Input: s = \"car\", p = \"c*v\"" << endl;
    cout << "Output: " << (solution.hasMatch(s2, p2) ? "true" : "false") << endl;

    // Example 3
    string s3 = "luck", p3 = "u*";
    cout << "\nExample 3:" << endl;
    cout << "Input: s = \"luck\", p = \"u*\"" << endl;
    cout << "Output: " << (solution.hasMatch(s3, p3) ? "true" : "false") << endl;

    // Additional Test Cases
    string s4 = "nrnrs", p4 = "*nn";
    cout << "\nAdditional Test Case 1:" << endl;
    cout << "Input: s = \"nrnrs\", p = \"*nn\"" << endl;
    cout << "Output: " << (solution.hasMatch(s4, p4) ? "true" : "false") << endl;
    return 0;
}