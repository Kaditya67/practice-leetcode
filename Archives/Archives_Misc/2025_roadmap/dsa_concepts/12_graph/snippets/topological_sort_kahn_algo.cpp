#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> kahnTopologicalSort(int n, vector<vector<int>> &adj) {
    vector<int> inDegree(n, 0);
    queue<int> q;
    vector<int> topoOrder;

    for (int i = 0; i < n; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    // Push nodes with in-degree = 0 into the queue
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        for (int neighbor : adj[node]) {
            inDegree[neighbor]--; 
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (topoOrder.size() == n) return topoOrder;
    return {};  
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    vector<int> topoSort = kahnTopologicalSort(n, adj);

    if (!topoSort.empty()) {
        cout << "Topological Order: ";
        for (int node : topoSort) {
            cout << node << " ";
        }
    } else {
        cout << "Cycle detected! Topological sort not possible.";
    }

    return 0;
}
