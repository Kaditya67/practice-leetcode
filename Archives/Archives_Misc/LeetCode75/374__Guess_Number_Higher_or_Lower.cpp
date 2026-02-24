// Problem: https://leetcode.com/problems/guess-number-higher-or-lower/
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num) {
    int x = 6; // This is the secret number
    if (num == x) return 0;
    else if (num > x) return -1;
    else return 1;
}

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int res = guess(mid);

            if (res == 0) return mid;
            else if (res < 0) r = mid - 1;
            else l = mid + 1;
        }

        return -1;
    }
};

int main() {
    Solution s;
    int n = 10;
    cout << s.guessNumber(n) << endl;
    return 0;
}