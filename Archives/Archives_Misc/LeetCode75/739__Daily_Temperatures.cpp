// Problem: https://leetcode.com/problems/daily-temperatures/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){    // Next temperature is greater, store result of previous day as today's index
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = s.dailyTemperatures(temperatures);
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
    return 0;
}
