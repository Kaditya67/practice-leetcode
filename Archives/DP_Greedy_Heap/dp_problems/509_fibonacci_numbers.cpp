#include<iostream>
#include<vector>
using namespace std;

// DP Top Down Approach
int solve(int n,vector<int> &dp){
    if(n<2){
        return n;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    return dp[n]=solve(n-1,dp)+solve(n-2,dp);
}

int main(){

    int n;
    cin>>n;

    // Brute Force Approach O(n) TIme Complexity     O(1) (constant space)
    // int a=0,b=1,c=0;
    // cout<<a<<" "<<b<<" ";
    // for(int i=2;i<n;i++){
    //     c=a+b;
    //     cout<<c<<" ";
    //     a=b;
    //     b=c;
    // }


    // Dynamic Programming (Bottom-Up Approach) O(n) TIme Complexity     O(n) (constant space)

    // vector<int> dp(n+1,0);
    // dp[1]=1;
    // cout<<dp[0]<<" "<<dp[1]<<" ";
    // for(int i=2;i<n;i++){
    //     dp[i]=dp[i-1]+dp[i-2];
    //     cout<<dp[i]<<" ";
    // }


    // Dynamic Programming (Top-Down Approach with Memoization) O(n) TIme Complexity     O(n) (constant space)
    vector<int> dp(n+1,0);
    dp[1]=1;

    solve(n,dp);

    // printing the dp array
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }

    return 0;
}