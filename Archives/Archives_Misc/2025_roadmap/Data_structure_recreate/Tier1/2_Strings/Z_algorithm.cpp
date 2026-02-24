#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Function to compute the Z-array
vector<int> computeZ(const string& s) {
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0; 
    for(int i = 1; i < n; i++) {
        if(i > r) {
            l = r = i;
            while(r < n && s[r] == s[r - l]) {
                r++;
            }
            z[i] = r - l;
            r--;
        } else {
            int k = i - l;
            if(z[k] < r - i + 1) {
                z[i] = z[k];
            } else {
                l = i;
                while(r < n && s[r] == s[r - l]) {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }

    // Print the Z-array
    cout << "\nZ-array:\n";
    for(int i = 0; i < n; i++) {
        cout << "z[" << i << "] = " << z[i] << endl;
    }

    return z;
}

// Function to find all occurrences of a pattern in a text using Z-algorithm
void ZAlgorithmSearch(const string& text, const string& pattern) {
    string concat = pattern + "$" + text;
    vector<int> z = computeZ(concat);
    int patternLength = pattern.length();
    cout << "\nMatch locations:\n";
    for(int i = 0; i < z.size(); i++) {
        if(z[i] == patternLength) {
            cout << "Pattern found at index " << i - patternLength - 1 << endl;
        }
    }
}

int main() {
    string text = "ababcababc";
    string pattern = "ababc";
    cout << "Text: " << text << "\nPattern: " << pattern << endl;

    ZAlgorithmSearch(text, pattern);

    return 0;
}
