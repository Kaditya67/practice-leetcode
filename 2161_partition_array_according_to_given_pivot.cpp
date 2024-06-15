#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> before;
        vector<int> after;
        int countDup=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                before.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
                after.push_back(nums[i]);
            }
            else{
                countDup++;
            }
        }

        while(countDup>0){
            before.push_back(pivot);
            countDup--;
        }

        for(int i=0;i<after.size();i++){
            before.push_back(after[i]);
        }

        return before;
    }
};

int main(){

    Solution s;

    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;

    vector<int> result = s.pivotArray(nums, pivot);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    cout<<endl;

    return 0;
}