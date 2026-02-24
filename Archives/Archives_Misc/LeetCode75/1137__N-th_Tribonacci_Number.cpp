// Problem: https://leetcode.com/problems/n-th-tribonacci-number/
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        int t0 = 0, t1 = 1, t2 = 1, res = 0;
        for (int i = 3; i <= n; ++i) {
            res = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = res;
        }
        return res;
    }
};

int main() {
    Solution solution;
    int n = 4; // Example input
    cout << "The " << n << "-th Tribonacci number is: " << solution.tribonacci(n) << endl;
    return 0;
}