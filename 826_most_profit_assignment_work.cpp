#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        ios::sync_with_stdio(0);
        cout.tie(0);
        cin.tie(0);
        vector<pair<int,int>> jobs;

        int n=profit.size();

        for(int i=0;i<n;i++)
            jobs.push_back({difficulty[i],profit[i]});
        sort(jobs.begin(),jobs.end());

        sort(worker.begin(),worker.end());
        int ans=0;
        int i=0;
        int j=0;
        int res=0;
        while(j<worker.size()){

            while(i<n && jobs[i].first<=worker[j]){
                ans=max(ans,jobs[i].second);        // store the biggest value
                i++;
            }
            j++;

            res+=ans;
        }

        return res;

    }
};


int main(){
    vector<int> difficulty={2,4,6,8,10};
    vector<int> profit={10,20,30,40,50};
    vector<int> worker={4,5,6,7};
    Solution obj;   

    cout<<obj.maxProfitAssignment(difficulty,profit,worker);
    return 0;
}