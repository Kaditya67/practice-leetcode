// Problem: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int& reversals) {
        visited[node] = true;

        for (auto& [neighbor, needsReversal] : adj[node]) {
            if (!visited[neighbor]) {
                if (needsReversal == 1) reversals++;
                dfs(neighbor, adj, visited, reversals);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);  

        // Build graph with direction
        for (auto& edge : connections) {
            int from = edge[0];
            int to = edge[1];
            adj[from].push_back({to, 1}); // needs reversal
            adj[to].push_back({from, 0}); // already correct
        }

        vector<bool> visited(n, false);
        int reversals = 0;

        dfs(0, adj, visited, reversals);

        return reversals;
    }
};

int main() {
    Solution s;
    int n = 6;
    vector<vector<int>> connections = {
        {0,1}, {1,3}, {2,3}, {4,0}, {4,5}
    };
    cout << s.minReorder(n, connections) << endl;
    return 0;
}
