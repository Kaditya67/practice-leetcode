#include <iostream>
#include <vector>
#include <string>
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

void KMPsearch(const string& text, const string& pattern) {
    vector<int> lps = computeLPS(pattern); // Compute LPS array
    int n = text.length();
    int m = pattern.length();
    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while(i < n) {
        if(pattern[j] == text[i]) { // Characters match then keep moving
            i++;
            j++;
        }
        if(j == m) {
            cout << "Pattern found at index " << i - j << endl; // Pattern found
            j = lps[j - 1]; // Always Reset j using LPS on Pattern
        } else if(i < n && pattern[j] != text[i]) {
            if(j != 0) {    // Only if j is not 0
                j = lps[j - 1]; // Fall back in the pattern
            } else {    // Now j is 0 and No match, so move to next character in text
                i++; // Move to the next character in text
            }
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text; // Input the text
    cout << "Enter the pattern: ";
    cin >> pattern; // Input the pattern

    KMPsearch(text, pattern); // Perform KMP search

    return 0; // Exit the program
}

// Example usage:
// Input: text = "ababcabcabababd", pattern = "ababd"