class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums,int i,int j){
        if(i>j) return 0;

        if(dp[i]!=-1) return dp[i];

        int steal = nums[i] + solve(nums,i+2,j);
        int skip = solve(nums,i+1,j);
        return dp[i] = max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,n-1);
    }
}

int main(){

    Solution s;
    vector<int> nums = {1,2,3,1};
    cout<<s.rob(nums);
    return 0;
}