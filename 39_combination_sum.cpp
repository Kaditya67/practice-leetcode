#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void find(int ind,int target,vector<int>&candidates,vector<vector<int>>&ans,vector<int>&ds){
        if(ind==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return ;
        }
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            find(ind,target-candidates[ind],candidates,ans,ds);
            ds.pop_back();
        }
        find(ind+1,target,candidates,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        find(0,target,candidates,ans,ds);
        return ans;
    }
};

int main(){
    vector<int>candidates={2,3,6,7};
    int target = 7;
    Solution obj;
    vector<vector<int>>ans = obj.combinationSum(candidates,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}