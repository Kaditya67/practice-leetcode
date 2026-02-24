// Problem: https://leetcode.com/problems/counting-bits/
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

// Using bit manipulation to count bits
// Time Complexity: O(n * log n), Space Complexity: O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int i = 0; i <= n; ++i) {
            int count = 0;
            int num = i;
            while (num != 0) {
                if ((num & 1) == 1) count++;
                num >>= 1;
            }
            res[i] = count;
        }
        return res;
    }
};

// Using dynamic programming to count bits
// Time Complexity: O(n), Space Complexity: O(n)
class Solution2 {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int i = 1; i <= n; ++i) {
            int half = i >> 1;                  // Use results from previously half computed values
            int lsb = i & 1;                    // Least significant bit (0 or 1)
            res[i] = res[half] + lsb;           // If 0 then no change from lsb, if 1 then add 1 to the count
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> res = s.countBits(5);
    for (int i : res) cout << i << " ";
    cout << endl;
    return 0;
}

