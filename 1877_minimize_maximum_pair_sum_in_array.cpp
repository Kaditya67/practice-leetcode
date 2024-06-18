#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPairSum(std::vector<int>& nums) {
        
        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int result = 0;

        while (i < j) {
            int temp = nums[i] + nums[j];
            result = std::max(result, temp);
            ++i;
            --j;
        }

        return result;
    }
};

int main(){

    std::vector<int> nums = {3, 5, 2, 3};

    Solution s;

    std::cout << s.minPairSum(nums) << std::endl;

    return 0;
}