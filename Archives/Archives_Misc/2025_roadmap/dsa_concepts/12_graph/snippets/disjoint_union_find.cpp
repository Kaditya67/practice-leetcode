#include <iostream>
#include <vector>

using namespace std;

class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]); 
        }
        return parent[node];
    }

    bool unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) return false; 

        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return true;
    }
};

int main() {
    int n = 6; 
    vector<pair<int, int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5} 
    };

    DSU dsu(n);
    bool cycle = false;

    cout << "Processing Graph Edges...\n";
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        cout << "Adding Edge: (" << u << " - " << v << ") ";
        
        if (!dsu.unionSet(u, v)) {
            cout << "[Cycle Detected]\n";
            cycle = true;
        } else {
            cout << "[Edge Added Successfully]\n";
        }
    }

    if (cycle)
        cout << "\nGraph contains a cycle.\n";
    else
        cout << "\nGraph is a Tree (No cycles).\n";

    return 0;
}
