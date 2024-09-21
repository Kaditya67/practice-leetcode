#include <iostream>
#include <cstring>
using namespace std;

// Recursive approach (Brute Force)
int solve(int n)
{
    if (n < 0)
        return 0; 
    if (n == 0)
        return 1;                       
    return solve(n - 1) + solve(n - 2);
}

// Dynamic Programming (Top-Down Approach with Memoization)
int solve(int n, int dp[])
{
    if (n == 0 || n == 1 || n == 2)
        return n; // Base cases
    if (dp[n] != -1)
        return dp[n];                            
    dp[n] = solve(n - 1, dp) + solve(n - 2, dp); 
    return dp[n];
}

// Dynamic Programming (Bottom-Up Approach)
int climbingStairs(int n)
{
    if (n == 0 || n == 1 || n == 2)
        return n;  
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2; 
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2]; 
    }
    return dp[n];
}

// Optimized Dynamic Programming (Bottom-Up Approach)
int opClimbingStairs(int n)
{
    if (n == 0 || n == 1 || n == 2)
        return n;

    int a = 1, b = 2, c = 0;
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    int dp[n + 1];             
    memset(dp, -1, sizeof(dp)); 
    cout << "Top-Down Approach: " << solve(n, dp) << endl;
    cout << "Bottom-Up Approach: " << climbingStairs(n) << endl;
    cout << "Optimized Bottom-Up: " << opClimbingStairs(n) << endl;

    return 0;
}
