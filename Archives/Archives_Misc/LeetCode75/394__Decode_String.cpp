#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> results;
        string curr;
        int k = 0;

        for(char ch : s) {
            if(isdigit(ch)) {
                k = k * 10 + (ch - '0');
            }
            else if(ch == '[') {
                counts.push(k);
                results.push(curr);
                k = 0;
                curr.clear();
            }
            else if(ch == ']') {
                int repeat = counts.top(); counts.pop();
                string prev = results.top(); results.pop();
                for(int i = 0; i < repeat; ++i)
                    prev += curr;
                curr = prev;
            }
            else {
                curr += ch;
            }
        }
        return curr;
    }
};


int main() {
    Solution s;
    string str = "3[a]2[bc]";
    cout << s.decodeString(str) << endl;
    return 0;
}
