// class Solution {
// public:
//     unordered_map<string,int>mp;
//     int solve(vector<int>&nums,int target,int i, int  currSum){
//         if(i==nums.size()){
//             if(currSum==target){
//                 return 1;
//             }else{
//                 return 0;
//             }
//         }

//         string key  = to_string(i)+"_"+to_string(currSum);
//         if(mp.count(key)) return mp[key];

//         int plus = solve(nums,target,i+1,currSum+nums[i]);
//         int minus = solve(nums,target,i+1,currSum-nums[i]);
//         return mp[key]=plus+minus;
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         return solve(nums,target,0,0);
//     }
// };

