#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> twoSumEqualtoTarget(vector<int> &nums, int target){
    int n = nums.size();
    int l = 0,r=n-1;
    while(l<r){
        int sum = nums[l]+nums[r];
        if(sum==target) return {nums[l],nums[r]};
        else if(sum<target) l++;
        else r--;
    }
    return {};
}
int main(){
    vector<int> arr = {2,3,4,1,7,5,9,10,25,11,16,13};
    int target = 15;
    sort(arr.begin(),arr.end());

    vector<int> res = twoSumEqualtoTarget(arr, target);
    if(res.size()==0) return 0;
    cout<< "Result is : { "<<res[0]<<", "<<res[1]<<" }"<< endl;
    return 0;
}
