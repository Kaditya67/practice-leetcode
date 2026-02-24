// Problem: https://leetcode.com/problems/number-of-provinces/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true;

        for (int other = 0; other < isConnected.size(); ++other) {
            if (isConnected[city][other] == 1 && !visited[other]) {
                dfs(other, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if(!visited[i]){        // If two provinces are connected then they are considered one
                dfs(i,isConnected,visited);     
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    cout << s.findCircleNum(isConnected) << endl;
    return 0;
}
