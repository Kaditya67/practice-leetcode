#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <cstring> // memoization memset

using namespace std;

class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        int n = s.size();
        unordered_set<string> dt(begin(dictionary), end(dictionary)); // Convert dictionary to a set for faster lookup
        vector<int> t(n + 1, 0);                                      // DP table to store the results, initialized to 0

        // Fill the DP table from the end of the string to the beginning
        for (int i = n - 1; i >= 0; i--)
        {
            t[i] = 1 + t[i + 1]; // Default case: count the current character as an extra character

            for (int j = i; j < n; j++)
            {
                if (dt.count(s.substr(i, j - i + 1)))
                {
                    t[i] = min(t[i], t[j + 1]); // If the substring is in the dictionary, take the minimum
                }
            }
        }

        return t[0]; // Return the result stored for the entire string
    }
};

int main()
{
    Solution s;
    vector<string> dictionary = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    cout << s.minExtraChar("aebec", dictionary) << endl;

    // "leetscode", dictionary = ["leet","code","leetcode"]
    vector<string> dictionary1 = {"leet", "code", "leetcode"};
    cout << s.minExtraChar("leetscode", dictionary1) << endl;

    vector<string> dictionary2 = {"gw", "lq", "yzqch", "sah", "giieb", "kfqczw", "qxqz", "jb", "ucxmpe", "hpwr", "y", "vzlhe", "i", "kn", "ip", "iafwk", "zl", "dw", "yhxeqi", "egktb", "xasq", "f", "c", "vrllz", "p", "uowgo", "pgxd", "gnjgkm", "rnug", "sa", "vfccq", "j"};
    cout << s.minExtraChar("enknouowgowcipfipojlrpuowgoiogiiebfjiafwksaigjyd", dictionary2) << endl;
    return 0;
}

// // without memoization

// class Solution {
// public:
//     int solve(int i, string &s, int n, unordered_set<string> &dt) {
//         if(i >= n) return 0;

//         int result = 1 + solve(i + 1, s, n, dt);

//         for(int j = i ; j < n; j++) {
//             string word = s.substr(i, j - i + 1);

//             if(dt.count(word)) {
//                 result = min(result, solve(j + 1, s, n, dt));       // if present take 0 not the count of characters
//             }
//         }

//         return result;
//     }
//     int minExtraChar(string s, vector<string>& dictionary) {
//         int n = s.size();
//         unordered_set<string> dt(begin(dictionary), end(dictionary));
//         return solve(0,s, n, dt);

//     }
// };

// // with memoization

// class Solution {
// public:
//     int t[51];
//     int solve(int i, string &s, int n, unordered_set<string> &dt) {
//         if(i >= n) return 0;

//         if(t[i] != -1) return t[i];

//         int result = 1 + solve(i + 1, s, n, dt);

//         for(int j = i ; j < n; j++) {
//             string word = s.substr(i, j - i + 1);

//             if(dt.count(word)) {
//                 result = min(result, solve(j + 1, s, n, dt));       // if present take 0 not the count of characters
//             }
//         }

//         return t[i] = result;
//     }
//     int minExtraChar(string s, vector<string>& dictionary) {
//         int n = s.size();
//         memset(t, -1, sizeof(t));
//         unordered_set<string> dt(begin(dictionary), end(dictionary));
//         return solve(0,s, n, dt);

//     }
// };