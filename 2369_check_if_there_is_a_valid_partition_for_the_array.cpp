#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool validPartition(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;

        // A vector to store whether there's a valid partition up to the ith index
        std::vector<bool> dp(n + 1, false);
        dp[0] = true; // Base case, an empty array is trivially valid

        for (int i = 1; i < n; ++i) {
            // Check for the subarray of exactly 2 equal elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                dp[i + 1] = dp[i + 1] || dp[i - 1];
            }
            // Check for the subarray of exactly 3 equal elements
            if (i > 1 && nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
                dp[i + 1] = dp[i + 1] || dp[i - 2];
            }
            // Check for the subarray of exactly 3 consecutive increasing elements
            if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1) {
                dp[i + 1] = dp[i + 1] || dp[i - 2];
            }
        }

        return dp[n];
    }
};

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 2, 3, 3};
    Solution s;
    std::cout << s.validPartition(nums) << std::endl;
    return 0;   
}