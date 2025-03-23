#include<iostream>
#include<vector>

using namespace std;

void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[start] = true;
    
    for (int neighbor : adj[start]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n = 6; 
    vector<vector<int>> adj(n);

    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {1, 2, 5};
    adj[5] = {3, 4};

    vector<bool> visited(n, false);

    cout << "DFS Traversal: ";
    dfs(0, adj, visited);

    return 0;
}