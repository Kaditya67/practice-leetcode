#include<iostream>
#include<vector>
using namespace std;

int waysToSplitArray(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;

    for(int i=0; i<n; i++){
        sum += nums[i];
    }

    int prefixSum = 0;
    int count = 0;

    for(int i=0; i<n-1; i++){
        prefixSum += nums[i];
        if(prefixSum > sum - prefixSum){
            count++;
        }
    }
    return count;
}

int main(){
    vector<int> nums = {10,4,-8,7};
    cout<<waysToSplitArray(nums);
    return 0;
}