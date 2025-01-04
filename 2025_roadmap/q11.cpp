#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        string a = "";
        int count = 0;
        for (auto c : p) {
            if (c != '*') {
                a += c;
            }else{
                count++;
            }
        }

        int i = 0, j = 0; 
        while (i < s.size() && j < a.size()) {
            if (s[i] == a[j]) { 
                j++; 
            }
            i++; 
        }

        return j == a.size();
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