#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        int leftSum = 0;

        // Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // If leftSum is equal to the remaining sum after excluding the current element
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }

        // Return -1 if no pivot index is found
        return -1;
    }
};

int main(){
    
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    Solution s;
    cout << s.pivotIndex(nums);

    return 0;
}