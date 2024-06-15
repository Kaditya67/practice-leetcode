#include<iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> sortEvenOdd(std::vector<int>& nums) {
        // even indices ---> ascending order
        // odd indices ---> descending order
        int n = nums.size();
        if (n < 2) {
            return nums;
        }

        // Vectors to hold values at even and odd indices
        std::vector<int> even;
        std::vector<int> odd;

        // Separate the numbers based on their indices
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                even.push_back(nums[i]);
            } else {
                odd.push_back(nums[i]);
            }
        }

        // Sort the even index elements in ascending order
        std::sort(even.begin(), even.end());

        // Sort the odd index elements in descending order
        std::sort(odd.begin(), odd.end(), std::greater<int>());
        
        std::vector<int> ans(n);
        int evenIndex = 0, oddIndex = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                ans[i] = even[evenIndex++];
            } else {
                ans[i] = odd[oddIndex++];
            }
        }

        return ans;
    }
};

int main(){

    Solution s;
    std::vector<int> nums = {4, 1, 2, 3};
    std::vector<int> ans = s.sortEvenOdd(nums);
    for(int i=0;i<ans.size();i++){
        std::cout<<ans[i]<<" ";
    }
    return 0;
}
