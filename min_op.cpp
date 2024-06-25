#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 3 == 1) {
                count++;
            } else if (nums[i] % 3 == 2) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution s;
    cout << s.minimumOperations(nums) << endl;  // Output: 3

    vector<int> nums2 = {3, 6, 9};
    cout << s.minimumOperations(nums2) << endl;  // Output: 0

    return 0;
}
