#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0;
        int maxLen = 0;
        int countZero = 0;

        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] == 0) {
                countZero++;
            }
            while (countZero > 1) {
                if (nums[start] == 0) {
                    countZero--;
                }
                start++;
            }
            maxLen = max(maxLen, end - start);
        }

        return maxLen;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << s.longestSubarray(nums) << endl;
    return 0;
}