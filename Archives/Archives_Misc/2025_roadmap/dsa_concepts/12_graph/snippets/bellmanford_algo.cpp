#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
};

vector<int> bellmanFord(int n, int src, vector<Edge> &edges) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Relax all edges (V-1) times
    for (int i = 0; i < n - 1; i++) {
        for (auto edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for (auto edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            return {}; 
        }
    }

    return dist; 
}

int main() {
    int n = 5; 
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3},
        {1, 3, 2}, {1, 4, 2}, {3, 2, 5},
        {3, 1, 1}, {4, 3, -3}
    };

    int src = 0; 
    vector<int> shortest_paths = bellmanFord(n, src, edges);

    if (shortest_paths.empty()) {
        cout << "Graph contains a negative weight cycle.\n";
    } else {
        cout << "Shortest distances from node " << src << ":\n";
        for (int i = 0; i < n; i++) {
            cout << "To node " << i << " : " << shortest_paths[i] << "\n";
        }
    }

    return 0;
}
