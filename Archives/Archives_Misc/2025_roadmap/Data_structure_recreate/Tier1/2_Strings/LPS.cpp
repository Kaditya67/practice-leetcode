#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::reverse
using namespace std;

// Function to compute the Longest Prefix Suffix (LPS) array
vector<int> computeLPS(const string& pattern) {
    int n = pattern.length();
    vector<int> lps(n, 0); // LPS array initialized to 0
    int len = 0; // Length of the previous longest prefix suffix
    for(int i=1;i<n;i++) {
        while(len > 0 && pattern[i] != pattern[len]) {
            len = lps[len - 1]; // Fall back in the LPS array
        }
        if(pattern[i] == pattern[len]) {
            len++;
            lps[i] = len; // Set the LPS value
        } else {
            lps[i] = 0; // No prefix suffix match
        }
    }
    return lps; // Return the computed LPS array
}

// Note : Total Length  - LPS[n-1](Longest Prefix Suffix is at the end of repeated substring) = length of the smallest repeating substring
bool repeatedSubstringPattern(const string& s) {
    int n = s.length();
    vector<int> lps = computeLPS(s);
    int len = lps[n - 1]; // Length of the longest prefix suffix
    return (len > 0 && n % (n - len) == 0);
}

string shortestPalindrome(const string& s) {
    int n = s.length();
    vector<int> lps = computeLPS(s);
    int len = lps[n - 1]; // Length of the longest prefix suffix
    string suffix = s.substr(0, len); // Culprit suffix
    reverse(suffix.begin(), suffix.end()); // Reverse it
    return suffix + s;
}

int main() {
    string pattern;
    cout << "Enter the pattern: ";
    cin >> pattern; // Input the pattern
    vector<int> lps = computeLPS(pattern); // Compute LPS array
    cout << "LPS Array: ";
    for(int i = 0; i < lps.size(); i++) {
        cout << lps[i] << " "; // Print the LPS array
    }
    cout << endl;

    if(repeatedSubstringPattern(pattern)) {
        cout << "The string can be constructed by repeating a substring." << endl;
    } else {
        cout << "The string cannot be constructed by repeating a substring." << endl;
    }

    string shortestPalin = shortestPalindrome(pattern);
    cout << "Shortest Palindrome: " << shortestPalin << endl;
    cout << "Length of the shortest palindrome: " << shortestPalin.length() << endl;
    cout << "Length of the original string: " << pattern.length() << endl;
    
    return 0; 
}