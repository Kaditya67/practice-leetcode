#include<bits/stdc++.h>
using namespace std;

// Brute Way
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;

        while (s.find("ab") != string::npos || s.find("ba") != string::npos) {  // If any found
            if (x > y && s.find("ab") != string::npos) {    // Get AB start index
                size_t idx = s.find("ab");
                s.erase(idx, 2); 
                score += x;
            } 
            else if (y > x && s.find("ba") != string::npos) {
                size_t idx = s.find("ba");
                s.erase(idx, 2);
                score += y;
            }else { 
                // If x == y or neither preferred pair found, remove whichever appears first
                size_t idx_ab = s.find("ab");
                if(idx_ab != string::npos){
                    s.erase(idx_ab, 2);
                    score += x;
                } else { 
                    size_t idx_ba = s.find("ba");
                    s.erase(idx_ba, 2);
                    score += y;
                }
            }
        }
        return score;
    }
};

// Better Way :  Stack
class Solution2 {
private:
    int removePairs(string &s, const string &pair, int value){
        string res; // Stack
        int score = 0;

        for(char ch:s){
            if(!res.empty() && res.back()==pair[0] && ch==pair[1]){
                res.pop_back();
                score+=value;
            }else{
                res.push_back(ch);
            }
        }
        s = res; // Update the s string
        return score;
    }
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        // Maqsad
        // 1. Remove all "ab" and "ba" pairs
        // 2. Remove those first who gives more value

        if (x >= y) {   // If x is greater then remove all "ab" then "ba"
            score += removePairs(s, "ab", x);
            score += removePairs(s, "ba", y);
        } else {
            score += removePairs(s, "ba", y);
            score += removePairs(s, "ab", x);
        }

        return score;
    }
};



int main() {
    Solution solution;
    string s = "cdbcbbaaabab";
    int x = 4;
    int y = 5;
    int score = solution.maximumGain(s, x, y);
    cout << "Maximum score: " << score << endl;
    return 0;
}

