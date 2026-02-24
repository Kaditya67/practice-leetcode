// Problem: https://leetcode.com/problems/product-of-array-except-self/
// Difficulty: Medium

// Get Exicted --> We are learning NEW PATTERN !
// Prefix / Suffix

#include<bits/stdc++.h>
using namespace std;

// This solution handles all edge case in a clear manner
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount=0;
        int product=1;
        for(int num:nums){
            if(num==0){
                zeroCount++;
            }else{
                product*=num;
            }
        }

        int n = nums.size();
        vector<int> res(n,0);
        if(zeroCount>1){
            return res;
        }

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                res[i]=product;
            }else if(zeroCount>0){
                res[i] = 0;
            }
            else{
                res[i]= (product/nums[i]);
            }
        }
        return res;
    }
};

// other solution - prefix/suffix
class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        int prefix = 1;
        int suffix = 1;
        for(int i=0;i<n;i++){
            res[i] = prefix;        // 1
            prefix *= nums[i]; 
        }

        for(int i=n-1;i>=0;i--){
            res[i] *= suffix;   // 6 * 1 = 6
            suffix *= nums[i]; // 2 * 4 = 8         // Prefix * Suffix
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums = {1,2,3,4};
    vector<int> res = s.productExceptSelf(nums);
    for(int i:res) cout << i << " ";
    cout << endl;
    return 0;
}

