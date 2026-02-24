#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // (weight, vertex)

class Graph {
    int V;
    vector<vector<pii>> adj;

public:
    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({w, v});
        adj[v].push_back({w, u}); // Undirected graph
    }

    void primMST() {
        vector<bool> inMST(V, false);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        vector<int> parent(V, -1);
        vector<int> key(V, INT_MAX);
        int totalCost = 0;

        key[0] = 0;  // Start from node 0
        pq.push({0, 0});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;

            inMST[u] = true;
            totalCost += key[u];

            for (auto &[wt, v] : adj[u]) {
                if (!inMST[v] && wt < key[v]) {
                    key[v] = wt;
                    parent[v] = u;
                    pq.push({wt, v});
                }
            }
        }

        cout << "MST Edges (u - v : weight):\n";
        for (int v = 1; v < V; ++v) {
            cout << parent[v] << " - " << v << " : " << key[v] << "\n";
        }

        cout << "Total Cost of MST: " << totalCost << "\n";
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4, 11);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 1);

    g.primMST();

    return 0;
}
