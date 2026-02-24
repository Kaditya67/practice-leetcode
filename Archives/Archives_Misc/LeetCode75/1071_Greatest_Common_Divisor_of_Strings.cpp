// Problem: https://leetcode.com/problems/greatest-common-divisor-of-strings/
// Difficulty: Easy


// Concept:
// GCD(a, b) is the largest number that divides both a and b without any remainder.

// ####################### GCD in Strings ################################
//? Now the fun part — how GCD helps in strings:

//* Let’s say:
// str1 = "ABCABCABC"
// str2 = "ABCABC"

//* What do you observe?
// They are made by repeating "ABC":

// str1 = "ABC" × 3
// str2 = "ABC" × 2

//! So, "ABC" is the common pattern that repeats to build both.

// If str1 and str2 can be built by repeating the same pattern, then the length of that pattern must divide both str1.length() and str2.length().

// Thus, the length of the common base string = GCD(len1, len2)


#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1) return "";

    int len = gcd(str1.size(), str2.size());
    return str1.substr(0, len);
}

int main() {
    cout << gcdOfStrings("ABCABC", "ABC") << endl;
    return 0;
}
