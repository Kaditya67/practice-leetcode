// Problem: https://leetcode.com/problems/min-cost-climbing-stairs/
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i=2;i<n;++i){
            int curr = cost[i]+min(prev2,prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1,prev2);
    }
};

int main() {
    Solution s;
    vector<int> cost = {10, 15, 20};
    cout << s.minCostClimbingStairs(cost) << endl; // 15

    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << s.minCostClimbingStairs(cost2) << endl; // 6

    return 0;
}

