#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int parX = find(x);
        int parY = find(y);
        if (parX == parY) return false; // already in the same set

        if (rank[parX] < rank[parY])
            parent[parX] = parY;
        else if (rank[parX] > rank[parY])
            parent[parY] = parX;
        else {
            parent[parY] = parX;
            rank[parX]++;
        }
        return true;
    }
};

class Graph {
    int V;
    vector<Edge> edges;

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end());
        DSU dsu(V);

        int mstCost = 0;
        vector<Edge> mstEdges;

        for (auto &edge : edges) {
            if (dsu.unite(edge.u, edge.v)) {
                mstEdges.push_back(edge);
                mstCost += edge.weight;
            }
        }

        cout << "Minimum Spanning Tree Edges:\n";
        for (auto &e : mstEdges)
            cout << e.u << " - " << e.v << " : " << e.weight << "\n";

        cout << "Total Cost of MST: " << mstCost << "\n";
    }
};

int main() {
    int V = 6;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 0, 4);
    g.addEdge(2, 0, 4);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 4, 3);
    g.addEdge(5, 4, 3);

    g.kruskalMST();

    return 0;
}
