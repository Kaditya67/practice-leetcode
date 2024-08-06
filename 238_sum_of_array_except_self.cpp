#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // This will hold the final result
        vector<int> nums2; 

        // Iterate over each element in the input array
        for(int i = 0; i < nums.size(); i++) {
            // Initialize products of elements to the left and right of the current index
            int leftpartProd = 1; k
            int rightpartProd = 1;

            // Calculate the product of elements to the left of the current index
            for(int j = i - 1; j >= 0; j--)
                leftpartProd *= nums[j];

            // Calculate the product of elements to the right of the current index
            for(int j = nums.size() - 1; j > i; j--)
                rightpartProd *= nums[j];

            // Store the product of leftpartProd and rightpartProd in nums2
            nums2.push_back(leftpartProd * rightpartProd);
        }

        return nums2;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = solution.productExceptSelf(nums);

    cout << "Output: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
