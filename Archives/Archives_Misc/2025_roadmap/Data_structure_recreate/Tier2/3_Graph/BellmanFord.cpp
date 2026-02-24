#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

class Graph {
    int V, E;
    vector<Edge> edges;

public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    void bellmanFord(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Step 1: Relax all edges (V - 1) times
        for (int i = 0; i < V - 1; ++i) {
            for (auto &edge : edges) {
                if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
                    dist[edge.v] = dist[edge.u] + edge.weight;
                }
            }
        }

        // Step 2: Check for negative weight cycles
        for (auto &edge : edges) {
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
                cout << "Negative weight cycle detected!\n";
                return;
            }
        }

        // Step 3: Print shortest distances
        cout << "Vertex\tDistance from Source " << src << "\n";
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INT_MAX)
                cout << i << "\tINF\n";
            else
                cout << i << "\t" << dist[i] << "\n";
        }
    }
};

int main() {
    int V = 5; // vertices
    int E = 8; // edges
    Graph g(V, E);

    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    g.bellmanFord(0);

    return 0;
}


// Algorithm	    Purpose	                        Handles Neg Weights?	 Detects Cycle?	          Best For
// Bellman-Ford	    Single-source shortest path	    ✅ Yes	                ✅ Negative cycles	    Sparse graphs
// Floyd-Warshall	All-pairs shortest path	        ✅ Yes	                ✅ Negative cycles	    Dense graphs (≤ 500)
// Kruskal's	    Minimum Spanning Tree (MST)	    ❌ No	                ✅ Avoids cycles	        Edge list graphs
// Prim's	        Minimum Spanning Tree (MST)	    ❌ No	                ✅ Avoids cycles	        Dense graphs
