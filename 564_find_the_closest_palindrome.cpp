// TLE Solution

// class Solution {
// private:
//     bool checkPalindrome(string num) {
//         int i = 0;
//         int n = num.size();
//         while (i < n / 2) {
//             if (num[i] != num[n - 1 - i])
//                 return false;
//             i++;
//         }
//         return true;
//     }

//     string findClosestPalindrome(long long num, bool higher) {
//         long long candidate = num + (higher ? 1 : -1);
//         while (!checkPalindrome(to_string(candidate))) {
//             candidate += (higher ? 1 : -1);
//         }
//         return to_string(candidate);
//     }

// public:
//     string nearestPalindromic(string n) {
//         long long num = stoll(n); // Convert the string to a long long int
//         string highNum = findClosestPalindrome(num, true);  
//         string lowNum = findClosestPalindrome(num, false); 

//         if (abs(num - stoll(lowNum)) > abs(stoll(highNum) - num)) {
//             return highNum;
//         } else {
//             return lowNum;
//         }
//     }
// };


// Optimised Approach
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        if (n.length() == 1) {
            return to_string(stoi(n) - 1); // Special case for single digit numbers
        }

        int digits = n.length();
        vector<long> candidates;

        // Case 1: One less than a power of 10
        candidates.push_back(pow(10, digits - 1) - 1);

        // Case 2: One more than a power of 10
        candidates.push_back(pow(10, digits) + 1);

        int mid = (digits + 1) / 2;
        long prefix = stol(n.substr(0, mid));

        // Case 3: Generate palindromes by mirroring the prefix
        vector<long> prefixes = {prefix - 1, prefix, prefix + 1};
        for (long p : prefixes) {
            string postfix = to_string(p);
            if (digits % 2 != 0) {
                postfix.pop_back(); // Remove the middle digit if the length is odd
            }
            reverse(postfix.begin(), postfix.end());
            string palindrome = to_string(p) + postfix;
            candidates.push_back(stol(palindrome));
        }

        long minDiff = LONG_MAX;
        long result;
        long num = stol(n);
        for (long candidate : candidates) {
            if (candidate != num && abs(candidate - num) < minDiff) {
                minDiff = abs(candidate - num);
                result = candidate;
            } else if (abs(candidate - num) == minDiff) {
                result = min(result, candidate);
            }
        }

        return to_string(result);
    }
};

int main() {
    Solution solution;

    vector<string> testCases = {
        "1",
        "9",
        "123",
        "12321",
        "1234321",
        "1000",
        "807045053224792883"
    };

    for (const string& testCase : testCases) {
        cout << "Nearest Palindromic to " << testCase << " is " << solution.nearestPalindromic(testCase) << endl;
    }

    return 0;
}
