#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
   void sortColors(vector<int>& nums) {
        
        // initialize variables:
        int low = 0, mid = 0, high = nums.size() - 1;
        
        // logic:
        while(mid <= high)
        {
            switch(nums[mid])
            {
                case 0: swap(nums[low++], nums[mid++]); break;
                
                case 1: mid++; break;
                
                case 2: swap(nums[mid], nums[high--]); break;
            }
        }
    }
};

// dry run

// 2,0,2,1,1,0
// low = 0 , mid=0  , high=n-1=5
// nums[mid]=2, swap with last element ---> 0,2,0,2,1,1,2  --->high--
// nums[mid]=0, do nothing   low++,mid++
// nums[mid]=2, swap with 2nd last element ---> 0,1,0,2,1,2,2 --->high--
// nums[mid]=1; mid++
// nums[mid]=0; swap with 2nd element, low and mid;     --> 0,0,1,2,1,2,2   ---> low++,mid++
// nums[mid]=2; --> swap with last 3rd element ---> 0,0,1,1,2,2,2       

// mid=4; high=5

//nums[mid]=2---> swap(2,2)-->high--=4
// nums[mid]=2; mid=4; high=4       --->high--=3

// condition false ---> out of loop


int main(){

    vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution s;

    s.sortColors(nums);

    for(int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }

    return 0;
}