// Problem: https://leetcode.com/problems/is-subsequence/
// Difficulty: Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n > m) return false;

        int i = 0;
        int j = 0;
        while(j < m && i < n){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }
        return i == n;
    }
};


int main() {
    Solution s;
    string s1 = "abc";
    string t1 = "ahbgdc";
    cout << s.isSubsequence(s1, t1) << endl; // true

    string s2 = "axc";
    string t2 = "ahbgdc";
    cout << s.isSubsequence(s2, t2) << endl; // false

    return 0;
}


//* Initial:
// s: a b c
//    ↑   (i = 0)

// t: a h b g d c
//    ↑         (j = 0)
// s[0] == t[0] → match → move both pointers


//? Step 1:
// s: a b c
//      ↑ (i = 1)

// t: a h b g d c
//      ↑       (j = 1)
// ❌ s[1] != t[1] → move only j


//* Step 2:
// s: a b c
//      ↑ (i = 1)

// t: a h b g d c
//        ↑   (j = 2)
// s[1] == t[2] → match → move both pointers


//? Step 3:
// s: a b c
//        ↑ (i = 2)

// t: a h b g d c
//          ↑ (j = 3)
// ❌ s[2] != t[3] → move only j


//? Step 4:
// s: a b c
//        ↑ (i = 2)

// t: a h b g d c
//            ↑ (j = 4)
// ❌ s[2] != t[4] → move only j


//* Step 5:
// s: a b c
//        ↑ (i = 2)

// t: a h b g d c
//              ↑ (j = 5)
// s[2] == t[5] → match → move both pointers


//? Step 6:
// s: a b c
//        ↑ (i = 3)   // end of s

// t: a h b g d c
//                ↑ (j = 6)

//! Result:
// ✅ i == s.length() → return true