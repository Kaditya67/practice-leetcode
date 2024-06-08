#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = -1;   // exceptional case

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int remainder = sum % k;

            // Handle negative remainders for negative k
            if (remainder < 0) {
                remainder += k;
            }

            // Check if it is present in the map
            if (mp.find(remainder) != mp.end()) {
                if (i - mp[remainder] >= 2) {
                    return true;
                }
            } else {
                mp[remainder] = i;        // If not seen, store in map
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {23, 2, 4, 6, 7};
    int k1 = 6;
    bool result1 = solution.checkSubarraySum(nums1, k1);
    cout << (result1 ? "True" : "False") << endl;

    // Test case 2
    vector<int> nums2 = {23, 2, 6, 4, 7};
    int k2 = 6;
    bool result2 = solution.checkSubarraySum(nums2, k2);
    cout << (result2 ? "True" : "False") << endl;

    // Test case 3
    vector<int> nums3 = {23, 2, 6, 4, 7};
    int k3 = 13;
    bool result3 = solution.checkSubarraySum(nums3, k3);
    cout << (result3 ? "True" : "False") << endl;

    return 0;
}
