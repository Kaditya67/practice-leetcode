#include <bits/stdc++.h>
using namespace std;

// If a node has in-degree = 0, it has no dependencies, so it can come first.
// Remove it, and reduce in-degree of its neighbors.
// Repeat...

class Graph {
    int V;
    vector<vector<int>> adjList;

public:
    // Constructor
    Graph(int v) {
        V = v;
        adjList.resize(V);
    }

    // Add directed edge from u → v
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    // Kahn's Algorithm (BFS-based Topological Sort)
    void topoSortKahn() {
        vector<int> inDegree(V, 0);

        // 1. Calculate in-degree of each node
        for (int u = 0; u < V; ++u) {
            for (int v : adjList[u]) {
                inDegree[v]++;      // InDegree of visiting node is increased...
            }
        }

        queue<int> q;

        // 2. Enqueue all nodes with in-degree 0
        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        // 3. Process the queue
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int neighbor : adjList[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // 4. Check for cycles
        if (topo.size() < V) {
            cout << "Cycle detected! No topological sort exists.\n";
            return;
        }

        // 5. Print topological order
        cout << "Topological Sort (Kahn's Algo): ";
        for (int node : topo)
            cout << node << " ";
        cout << "\n";
    }
};

// Example usage
int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topoSortKahn();

    return 0;
}
