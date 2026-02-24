#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

void floydWarshall(vector<vector<int>> &dist, int n) {
    for (int k = 0; k < n; k++) { 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) { 
                // Avoid integer overflow for INF values
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

void printSolution(const vector<vector<int>> &dist, int n) {
    cout << "Shortest distances between every pair of nodes:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) 
                cout << "INF\t";
            else 
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;

    vector<vector<pair<int, int>>> adj(n);
    
    adj[0] = {{1, 3}, {3, 5}};
    adj[1] = {{0, 2}, {3, 4}};
    adj[2] = {{1, 1}};
    adj[3] = {{2, 2}};

    // Convert Adjacency List to Distance Matrix
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
        for (auto &edge : adj[i]) {
            int neighbor = edge.first;
            int weight = edge.second;
            dist[i][neighbor] = weight;
        }
    }

    floydWarshall(dist, n);
    printSolution(dist, n);

    return 0;
}