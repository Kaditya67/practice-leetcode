#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSubseq(std::vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        const int MOD = 1e9 + 7;
        int n = nums.size();
        std::vector<int> power(n, 1);
        
        // Precompute powers of 2 up to 2^(n-1)
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i-1] * 2) % MOD;
        }
        
        std::sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        int result = 0;
        
        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                result = (result + power[j - i]) % MOD;
                ++i;
            } else {
                --j;
            }
        }
        
        return result;
    }
};

int main() {
    std::vector<int> nums = {3, 5, 6, 7};
    int target = 9;

    Solution sol;
    std::cout << sol.numSubseq(nums, target) << std::endl;

    return 0;
}
