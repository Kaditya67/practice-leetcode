#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        vector<int> count(26, 0);

        for (char &ch : s) {
            count[ch - 'a']++;
        }

        for (char &ch : t) {
            count[ch - 'a']--;
            if (count[ch - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    // Example usage
    Solution sol;
    string s = "anagram";
    string t = "nagaram";

    bool result = sol.isAnagram(s, t);

    // Print result
    cout << (result ? "True" : "False") << endl;

    return 0;
}
