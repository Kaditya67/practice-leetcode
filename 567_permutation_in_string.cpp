#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    bool compareArrays(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) return false;

        vector<int> count1(26, 0), count2(26, 0);

        // Count character frequencies in s1 and the initial window of s2
        for (int i = 0; i < n; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        // Slide the window and check for permutations
        for (int i = n; i < m; i++) {
            if (compareArrays(count1, count2)) {
                return true;
            }
            // Update count2 for the new window
            count2[s2[i] - 'a']++;
            // Decrease count2 for the character leaving the window
            count2[s2[i - n] - 'a']--;
        }

        // Check the last window
        return compareArrays(count1, count2);
    }
};

int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";
    Solution obj;
    bool ans = obj.checkInclusion(s1, s2);
    if (ans) {
        cout << "True";
    } else {
        cout << "False";
    }
    return 0;
}