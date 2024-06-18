#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int low=0,high=nums.size()-1,mid=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
};

int main()
{
    Solution obj;
    vector<int> nums={1,3,5,6};
    int target=5;
    cout<<obj.searchInsert(nums,target)<<endl;
    return 0;
}