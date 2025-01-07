#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        vector<string> arr;
        for(int i = 0; i < p.length(); i++) {
            if(p[i] == '*') {
                arr.push_back(p.substr(0, i));
                arr.push_back(p.substr(i + 1));
            }
        }
        
        if (arr.size() != 2) {
            return false; // if no '*' is found, no match
        }

        int l1 = s.find(arr[0]);
        if (l1 == string::npos) {
            return false;
        }

        int l2 = s.find(arr[1], l1 + arr[0].length());
        if (l2 == string::npos) {
            return false;
        }

        return true;
    }
};

int main() {
    Solution solution;
    
    string s = "abcdef";
    string p = "ab*ef";
    
    if (solution.hasMatch(s, p)) {
        cout << "The pattern matches the string!" << endl;
    } else {
        cout << "The pattern does not match the string." << endl;
    }

    s = "abcdef";
    p = "ab*gh";
    
    if (solution.hasMatch(s, p)) {
        cout << "The pattern matches the string!" << endl;
    } else {
        cout << "The pattern does not match the string." << endl;
    }

    return 0;
}
