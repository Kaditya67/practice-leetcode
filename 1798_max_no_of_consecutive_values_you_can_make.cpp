#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        
        sort(coins.begin(),coins.end());
        int maxReach=0; 
        int n=coins.size();
        for(int i=0;i<n;i++){
            if(coins[i]>maxReach+1){
                return maxReach+1;
            }
            else{
                maxReach+=coins[i];
            }
        }
        return maxReach+1;
    }
};

int main(){

    vector<int> coins = {1, 3};
    Solution s;
    cout<<s.getMaximumConsecutive(coins);
    
    return 0;
}