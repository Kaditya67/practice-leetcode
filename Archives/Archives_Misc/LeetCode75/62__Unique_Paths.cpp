// Problem: https://leetcode.com/problems/unique-paths/
// Difficulty: Medium
// can move: only down or right
#include<bits/stdc++.h>
using namespace std;

// Bottom-up DP approach
// Time Complexity: O(m*n), space Complexity: O(m*n)
// Explanation:

//  dp[0][0] = 0;   // Total ways to reach the starting point
//  dp[0][1] = 1;   // Total ways to reach the first cell in the first row
//  dp[1][0] = 1;   // Total ways to reach the first cell in the first column
//?  dp[1][1] = 2;   dp[1][1] = dp[0][1] + dp[1][0]             // // Total ways to reach the second cell in the second row
// Reach [1][1] from up or left
// For all cells in the first row and first column, there's only one way to reach them (either from the left or from above). // Fill them by 1
// Cells to fill are from [1][1] to [m-1][n-1]  // Least required cells to fill are [0][1] and [1][0]

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

// Space-optimized DP approach
// Space Complexity: O(n)
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1); // Only 1 row needed
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

// Recursive + memoization
// Time Complexity: O(m*n), space Complexity: O(m*n) for memoization
class Solution3 {
public:
    int solve(int i,int j, int m,int n, vector<vector<int>>& t){
        if(i==m-1 && j==n-1){
            return 1;   // Found
        }
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        if(t[i][j]!=-1) return t[i][j];

        int right = solve(i,j+1,m,n,t);
        int down = solve(i+1,j,m,n,t);
        return t[i][j] = right+down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,t);
    }
};

// Recursive + memoization
// Time Complexity: O(m*n), space Complexity: O(n) for memoization
class Solution4 {
public:
    int solve(int i, int j, int m, int n, vector<int>& dp) {
        if (i == m - 1 && j == n - 1) {
            return 1; // Found
        }
        if (i < 0 || i >= m || j < 0 || j >= n) return 0;
        if (dp[j] != -1) return dp[j];

        int right = solve(i, j + 1, m, n, dp);
        int down = solve(i + 1, j, m, n, dp);
        return dp[j] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<int> dp(n + 1, -1);
        return solve(0, 0, m, n, dp);
    }
};

int main(){
    Solution s1;
    Solution2 s2;
    Solution3 s3;
    Solution4 s4;
    cout<<s1.uniquePaths(3,7)<<endl;
    cout<<s2.uniquePaths(3,7)<<endl;
    cout<<s3.uniquePaths(3,7)<<endl;
    cout<<s4.uniquePaths(3,7)<<endl;
    return 0;
}
