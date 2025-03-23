#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);  
        }
        return parent[node];
    }

    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

vector<Edge> kruskalMST(int n, vector<Edge> &edges) {
    vector<Edge> mst;  
    sort(edges.begin(), edges.end(), compare);  

    DSU dsu(n);  
    int mst_weight = 0;

    for (Edge edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unionSet(edge.u, edge.v);
            mst.push_back(edge);
            mst_weight += edge.weight;
        }
    }

    return mst;  
}

int main() {
    int n = 5;  
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };

    vector<Edge> mst = kruskalMST(n, edges);

    for (Edge edge : mst) {
        cout << "Edge: (" << edge.u << " - " << edge.v << ") Weight: " << edge.weight << endl;
    }
    return 0;
}
