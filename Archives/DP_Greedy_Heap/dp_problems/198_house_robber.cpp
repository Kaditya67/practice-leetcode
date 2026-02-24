// // Bottom Up

// class Solution {
// public:
//     int dp[101];

//     // Solve function to recursively calculate the max amount we can rob
//     int solve(vector<int>& nums, int i, int j) {
//         if (i > j) return 0;

//         if (dp[i] != -1) {
//             return dp[i];
//         }
//         int steal = nums[i] + solve(nums, i + 2, j); // Option to rob current house
//         int skip = solve(nums, i + 1, j);            // Option to skip current house
        
//         dp[i] = max(steal, skip);
//         return dp[i];
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         memset(dp, -1, sizeof(dp));
//         int result = solve(nums, 0, n - 1);
//         return result;
//     }
// };



// Constant Space
#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return 0;
        
        if (n == 1) return nums[0];

        int prev = 0;  
        int curr = 0;  

        for(int i = 0; i < n; i++) { 
            int temp = curr; 
            curr = max(prev + nums[i], curr);
            prev = temp; 
        }

        return curr; 
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1}; 
    cout << s.rob(nums) << endl; 
    return 0;
}
