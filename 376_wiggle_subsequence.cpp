#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int inc=1;
        int dec=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                inc=dec+1;
            }else if(nums[i]<nums[i-1]){
                dec=inc+1;
            }
        }
        return max(inc,dec);

    }
};

int main(){

    vector<int> nums = {1, 7, 4, 9, 2, 5};
    Solution s;
    cout<<s.wiggleMaxLength(nums);  
    
    return 0;
}