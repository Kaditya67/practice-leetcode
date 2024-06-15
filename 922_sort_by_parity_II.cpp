#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     std::vector<int> sortArrayByParityII(std::vector<int>& nums) {
//         int evenIndex = 0;  
//         int oddIndex = 1;   
//         int n = nums.size();

//         while (evenIndex < n && oddIndex < n) {
           
//             if (nums[evenIndex] % 2 != 0) {
//                 while (oddIndex < n && nums[oddIndex] % 2 != 0) {
//                     oddIndex += 2;
//                 }
//                 if (oddIndex < n) {
//                     std::swap(nums[evenIndex], nums[oddIndex]);
//                 }
//             }
//             evenIndex += 2;
//         }

//         return nums;
//     }
// };


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>ans(n);
        int even=0;
        int odd=1;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]%2==0){
                ans[even]=(nums[i]);
                even+=2;
           }
          else{
               ans[odd]=(nums[i]);
               odd+=2;
          }
       }
        return ans;
    }
};

int main() {
    std::vector<int> nums = { 4, 2, 5, 7 };
    Solution obj;
    std::vector<int> result = obj.sortArrayByParityII(nums);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}