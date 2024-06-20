#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    bool allZero(const vector<int>& counter) {
        for (const int &i : counter) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }

public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> result;
        
        if (m > n) return result; // Early return if p is larger than s

        vector<int> counter(26, 0);

        // Initialize the counter with the frequencies of characters in p
        for (int i = 0; i < m; ++i) {
            counter[p[i] - 'a']++;
            counter[s[i] - 'a']--;
        }

        // Check the initial window
        if (allZero(counter)) {
            result.push_back(0);
        }

        // Slide the window over s
        for (int i = m; i < n; ++i) {
            counter[s[i] - 'a']--;
            counter[s[i - m] - 'a']++;

            if (allZero(counter)) {
                result.push_back(i - m + 1);
            }
        }

        return result;
    }
};
