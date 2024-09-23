// #include<iostream>
// #include<vector>
// #include<cstring>
// using namespace std;

// class Solution {
// public:
//     int dp[101];
//     int solve(vector<int>& nums,int i,int j){
//         if(i>j) return 0;

//         if(dp[i]!=-1) return dp[i];

//         int steal = nums[i] + solve(nums,i+2,j);
//         int skip = solve(nums,i+1,j);
//         return dp[i] = max(steal,skip);
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         memset(dp,-1,sizeof(dp));
//         return solve(nums,0,n-1);
//     }
// };

// int main(){

//     Solution s;
//     vector<int> nums = {1,2,3,1};
//     cout<<s.rob(nums);
//     return 0;
// }



#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution {
public:
    int dp[101];
    
    // Debugging function to print the state of dp array
    void printDP(int n) {
        cout << "DP Array State: [";
        for (int i = 0; i < n; i++) {
            cout << dp[i] << (i == n - 1 ? "]\n" : ", ");
        }
    }

    // Solve function to recursively calculate the max amount we can rob
    int solve(vector<int>& nums, int i, int j) {
        if (i > j) return 0;

        if (dp[i] != -1) {
            cout << "Returning memoized value dp[" << i << "] = " << dp[i] << endl;
            return dp[i];
        }

        cout << "Evaluating for i = " << i << endl;

        int steal = nums[i] + solve(nums, i + 2, j); // Option to rob current house
        int skip = solve(nums, i + 1, j);            // Option to skip current house
        
        dp[i] = max(steal, skip);
        
        cout << "At index " << i << ": Steal = " << steal << ", Skip = " << skip << ", dp[" << i << "] = " << dp[i] << endl;
        
        return dp[i];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        int result = solve(nums, 0, n - 1);
        
        printDP(n); // Print final DP array state
        return result;
    }
};

int main() {
    Solution s;
    
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Robbing result for nums = {1, 2, 3, 1}: " << s.rob(nums1) << endl;
    
    cout << "--------------------------------" << endl;

    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Robbing result for nums = {2, 7, 9, 3, 1}: " << s.rob(nums2) << endl;
    
    return 0;
}
