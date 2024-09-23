#include <iostream>
#include <algorithm>
#include <cstring>      // memcmp
using namespace std;

// bool checkPalindrome(string s,int n) {
//     for(int i=0;i<n/2;i++) {
//         if(s[i]!=s[n-1-i]) {
//             return false;
//         }
//     }
//     return true;
// }

string shortestPalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end()); 
    
    
    for (int i = 0; i < s.length(); i++) {
        
        if (!memcmp(s.c_str(), rev.c_str() + i, s.length() - i)) {
            // If they match, prepend the unmatched part of the reversed string to 's'
            return rev.substr(0, i) + s;
        }
    }
    
    // If no match, just return the reversed string concatenated with the original
    return rev + s;
}

int main() {
    string s = "abadz"; 
    cout << "Shortest palindrome: " << shortestPalindrome(s) << endl;
    return 0;
}
