#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

class Graph {
    int V;
    vector<vector<int>> dist;

public:
    Graph(int v) {
        V = v;
        dist.resize(V, vector<int>(V, INF));

        // Distance to self is 0
        for (int i = 0; i < V; ++i)
            dist[i][i] = 0;
    }

    void addEdge(int u, int v, int w) {
        dist[u][v] = w;  // Directed edge u → v
    }

    void floydWarshall() {
        // Triple nested loop
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Check for negative cycles
        for (int i = 0; i < V; ++i) {
            if (dist[i][i] < 0) {
                cout << "Negative weight cycle detected!\n";
                return;
            }
        }

        // Print the shortest distance matrix
        cout << "All-Pairs Shortest Path Matrix:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V = 4;
    Graph g(V);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 3, 10);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 1);

    g.floydWarshall();

    return 0;
}
