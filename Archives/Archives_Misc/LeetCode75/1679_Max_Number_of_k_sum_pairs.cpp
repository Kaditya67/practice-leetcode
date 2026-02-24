// Problem: https://leetcode.com/problems/max-number-of-k-sum-pairs/
// Difficulty: Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) { 
        int i = 0, j = nums.size()-1, count=0;
        sort(nums.begin(),nums.end());
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum == k){
                i++;
                j--;
                count++;
            }else if(sum>k){
                j--;
            }else{
                i++;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,1,3,4,3};
    int k = 6;
    cout << s.maxOperations(nums,k) << endl;
    return 0;
}
