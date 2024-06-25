#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> is_flipped(n, 0); // to track the flip state
        int flips = 0, flip_count = 0;

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                flip_count -= is_flipped[i - k];
            }

            // If the current bit is 0 and needs to be flipped
            if ((nums[i] + flip_count) % 2 == 0) {
                if (i + k > n) {
                    return -1; // not enough elements left to flip
                }
                flips++;
                flip_count++;
                is_flipped[i] = 1;
            }
        }
        return flips;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 0, 0, 1, 0, 1, 1, 0};
    int k = 3;
    int result = sol.minKBitFlips(nums, k);
    cout << "Minimum number of k-bit flips required: " << result << endl;

    return 0;
}
