#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V, timer = 0;
    vector<vector<int>> adj;
    vector<int> tin, low;
    vector<bool> visited;

public:
    Graph(int v) {
        V = v;
        adj.resize(V);
        tin.assign(V, -1);
        low.assign(V, -1);
        visited.assign(V, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected
    }

    void dfs(int u, int parent) {
        visited[u] = true;
        tin[u] = low[u] = timer++;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (!visited[v]) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                // Condition for bridge
                if (low[v] > tin[u]) {
                    cout << "Bridge: " << u << " - " << v << "\n";
                }
            } else {
                // Back edge
                low[u] = min(low[u], tin[v]);
            }
        }
    }

    void findBridges() {
        for (int i = 0; i < V; ++i)
            if (!visited[i])
                dfs(i, -1);
    }
};

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 6);

    g.findBridges();

    return 0;
}
