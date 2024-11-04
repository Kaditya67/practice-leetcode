// #include <iostream>
// #include <string>
// #include <cstring>
// #include <algorithm>
// #include <climits>

// using namespace std;

// // Top - Bottom Dynamic Programming Solution
// int t[101][27][101][101];

// class Solution {
// public:  
//     int solve(string& s, int i, int prev, int f, int k) {
//         if (k < 0) {
//             return INT_MAX; // Invalid case
//         }
//         if (i >= s.length()) {
//             return 0; // No characters left to process
//         }

//         if (t[i][prev][f][k] != -1) {
//             return t[i][prev][f][k]; // Return already computed result
//         }

//         // Option 1: Delete the current character
//         int delete_i = solve(s, i + 1, prev, f, k - 1);

//         // Option 2: Keep the current character
//         int keep_i = 0;
//         if (s[i] - 'a' != prev) {
//             keep_i = 1 + solve(s, i + 1, s[i] - 'a', 1, k);  
//         } else {
//             int one_more_add = (f == 1 || f == 9 || f == 99) ? 1 : 0;
//             keep_i = one_more_add + solve(s, i + 1, s[i] - 'a', f + 1, k);
//         }

//         return t[i][prev][f][k] = min(delete_i, keep_i); // Memoization
//     }

//     int getLengthOfOptimalCompression(string s, int k) {
//         memset(t, -1, sizeof(t)); // Initialize the DP table
//         return solve(s, 0, 26, 0, k);  
//     }
// };

// int main() {
//     Solution solution;
//     string s;
//     int k;

//     // Example input
//     cout << "Enter the string: ";
//     cin >> s;
//     cout << "Enter the maximum number of deletions (k): ";
//     cin >> k;

//     int result = solution.getLengthOfOptimalCompression(s, k);
//     cout << "The length of the optimal compression is: " << result << endl;

//     return 0;
// }

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

// Bottom-Up Dynamic Programming Solution
class Solution {
public:
    int dp[101][101]; 

    // Find the length required for the character
    int findNo(int n) {
        if (n == 1) return 1;        
        if (n > 1 && n < 10) return 2;   
        if (n >= 10 && n < 100) return 3; 
        return 4;   
    }

    int solve(string &s, int k, int i) {
        if (k < 0) return INT_MAX;  // Cannot be deleted
        if (i >= s.size() || (s.size() - i) <= k) return 0; // Can be deleted
        
        if (dp[i][k] != -1) return dp[i][k];
        
        // Option 1: Delete
        int ans = solve(s, k - 1, i + 1);

        // Option 2: Keep and group
        char c = s[i];      
        int count = 0;      
        int consecutive_len = 0; 
        int j;

        for (j = i; j < s.size() && count <= k; j++) {
            if (s[j] == c) {
                consecutive_len++;
            } else {
                ans = min(ans, findNo(consecutive_len) + solve(s, k - count, j));
                count++;
            }
        }

        if (count <= k) ans = min(ans, findNo(consecutive_len) + solve(s, k - count, j));

        return dp[i][k] = ans;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp)); 
        return solve(s, k, 0);      
    }
};

int main() {
    Solution solution;
    string s;
    int k;

    // Example input
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the maximum number of deletions (k): ";
    cin >> k;

    int result = solution.getLengthOfOptimalCompression(s, k);
    cout << "The length of the optimal compression is: " << result << endl;

    return 0;
}
