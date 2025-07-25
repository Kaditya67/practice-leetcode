// Problem: https://leetcode.com/problems/combination-sum-iii/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int k, int n, vector<vector<int>>& res, vector<int>& temp, int sum, int st){
        if(temp.size()==k){
            if(sum==n) res.push_back(temp);
        }

        for(int i=st;i<10;++i){
            if (sum + i > n) break;
            temp.push_back(i);  // Do
            solve(k, n, res, temp, sum + i, i + 1); // Explore
            temp.pop_back();    // Undo
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) { 
        vector<vector<int>> res;
        vector<int> temp;
        int sum=0;
        solve(k, n, res, temp, sum, 1);
        return res;
    }
};

int main() {
    Solution s;
    int k = 3, n = 7;
    vector<vector<int>> res = s.combinationSum3(k, n);
    for (const auto& combination : res) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}