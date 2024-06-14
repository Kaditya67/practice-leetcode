#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
     int n=nums.size();
     int left=0;
     int right=n-1;
     vector<int> v;

     while(left<=right){
        if(abs(nums[left])>abs(nums[right])){
            v.push_back(nums[left]*nums[left]);
            left++;
        }
        else{
             v.push_back(nums[right]*nums[right]);   
             right--;
        }
     }   
     reverse(v.begin(),v.end());
     return v;
    }
};

int main(){
    Solution s;

    vector<int> nums = {-4,-1,0,3,10};

    vector<int> v = s.sortedSquares(nums);
    for(int i=0;i<v.size();i++){    
        cout<<v[i]<<" ";
    }    
    return 0;
}