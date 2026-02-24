#include<iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int dp[101];

//     int solve(vector<int>& nums, int start, int end) {
//         if(start==end) return nums[start];

//         int prev2 = 0; 
//         int prev1 = 0; 
//         for (int i = start; i <= end; ++i) {
//             int current = max(prev1, prev2 + nums[i]); 
//             prev2 = prev1; 
//             prev1 = current;
//         }
//         return prev1;
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();

//         if (n == 1) return nums[0];
//         if (n == 2) return max(nums[0], nums[1]);

//         memset(dp, -1, sizeof(dp));
//         int result1 = solve(nums, 0, n - 2);

//         memset(dp, -1, sizeof(dp));
//         int result2 = solve(nums, 1, n - 1);

//         return max(result1, result2);
//     }
// };


// Constant Space

class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {

        int prev = 0;  
        int curr = 0;  

        for(int i = start; i <= end; i++) { 
            int temp = curr; 
            curr = max(prev + nums[i], curr);
            prev = temp; 
        }

        return curr;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int result1 = solve(nums, 0, n - 2);

        int result2 = solve(nums, 1, n - 1);

        return max(result1, result2);
    }
};

int main(){

    Solution s;
    vector<int> nums = {1,2,3,1};
    cout<<s.rob(nums);
    return 0;
}
