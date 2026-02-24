// Problem: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = 0;
        
        while( a != 0 || b != 0 || c != 0) {
            
            if( (c & 1) == 1) {
                if((a & 1) == 0 && (b & 1) == 0) {
                    result++;
                }
            } else {
                result += (a & 1) + (b & 1);
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
            
        }
        
        return result;
    }
};

int main() {
    Solution s;
    cout << s.minFlips(4, 2, 7) << endl;
    cout << s.minFlips(1, 6, 3) << endl;
    cout << s.minFlips(1, 2, 3) << endl;
    return 0;
}

// Explanation: Only 4 steps to understand the logic behind the code:
// Learning Step 1:
// (c & 1)
// Explanation: Bitwise AND of c and 1.

// What it does:
// Checks the least significant bit (LSB) of c.
// If c = 101 → c & 1 = 1
// If c = 100 → c & 1 = 0


// Learning Step 2:
// if ((c & 1) == 1)
// What it does:
// If the current bit of c is 1, we need at least one of a or b to be 1 in that bit position.


// Learning Step 3:
// if ((a & 1) == 0 && (b & 1) == 0)
// What it does:
// If both a and b have 0 at this bit position, but c wants 1, we need 1 flip to make either a or b bit 1.
// So:
// a = 0, b = 0, c = 1 → need to flip one to 1 → result++


// Learning Step 4:
// c >>= 1;
// What it does:
// Right-shifts each number by 1.
// Removes the current LSB and moves to the next higher bit.

// Example:
// a = 101 → becomes 10 (i.e. decimal 5 → 2)
// Essentially: discarding the bit we just processed.