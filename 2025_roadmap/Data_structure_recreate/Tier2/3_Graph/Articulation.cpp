#include<bits/stdc++.h>
using namespace std;

class GraphAP {
    int V, timer = 0;
    vector<vector<int>> adj;
    vector<int> tin, low;
    vector<bool> visited, isArticulation;

public:
    GraphAP(int v) {
        V = v;
        adj.resize(V);
        tin.assign(V, -1);
        low.assign(V, -1);
        visited.assign(V, false);
        isArticulation.assign(V, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected
    }

    void dfs(int u, int parent) {
        visited[u] = true;
        tin[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;
            if (!visited[v]) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if (low[v] >= tin[u] && parent != -1)
                    isArticulation[u] = true;

                children++;
            } else {
                low[u] = min(low[u], tin[v]);
            }
        }

        // Special case for root
        if (parent == -1 && children > 1)
            isArticulation[u] = true;
    }

    void findArticulationPoints() {
        for (int i = 0; i < V; ++i)
            if (!visited[i])
                dfs(i, -1);

        cout << "Articulation Points:\n";
        for (int i = 0; i < V; ++i)
            if (isArticulation[i])
                cout << i << " ";
        cout << "\n";
    }
};
