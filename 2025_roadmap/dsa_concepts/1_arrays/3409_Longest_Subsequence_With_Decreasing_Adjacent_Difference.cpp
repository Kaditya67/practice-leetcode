#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        static int dp[10001][301], mx[10001][301];

        // Initializing dp and mx arrays
        for (int i = 0; i < n; i++) {
            for (int d = 0; d <= 300; d++) {
                dp[i][d] = 1;
                mx[i][d] = 1;
            }
        }

        // Process the numbers
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int d = abs(nums[i] - nums[j]);
                dp[i][d] = max(dp[i][d], mx[j][d] + 1);
                ans = max(ans, dp[i][d]);
            }

            // Update the mx array
            for (int d = 300; d >= 0; d--) {
                mx[i][d] = max(mx[i][d + 1], dp[i][d]);
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 6, 9, 12};
    int result = solution.longestSubsequence(nums);
    cout << "Length of longest subsequence: " << result << endl;
    return 0;
}
