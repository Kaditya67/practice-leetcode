#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPrefixOfReversedSuffix(string &str1, string &str2) {
        int n = str1.size();
        int m = str2.size();
        if (n > m) return false;
        for (int i = 0; i < n; i++) {
            if (str1[i] != str2[m - n + i]) return false;
        }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i != j && isPrefixOfReversedSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<string> words = {"abc", "cba", "abc", "abcd"};
    Solution sol;
    cout << "Count of Prefix-Suffix Pairs: " << sol.countPrefixSuffixPairs(words) << endl;
    return 0;
}
