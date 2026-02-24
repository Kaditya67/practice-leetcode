#include <bits/stdc++.h>
using namespace std;

// "Sets in DSU are disjoint unless you union them"

// So, by default:
// - All sets start separate: {0}, {1}, {2}, ..., {n-1}
// - They only merge via unionSet(u, v)             ---> Union
// - So the intersection is NULL for any two unmerged sets.

// If from same set then both are same  ---> Find
class DSU {
private:
    vector<int> parent;    
    vector<int> rank;  // or size

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find with path compression
    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);        // Find next parent and store ---> Path compression
        return parent[u];
    }

    // Union by rank
    void unionSet(int u, int v) {
        int pu = find(u);       // One parent
        int pv = find(v);       // Second Parent
        if (pu == pv) return;           // If same then no need to union

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {                    // If ranks are same, choose any 1 parent and increase the parent's rank
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    bool isConnected(int u, int v) {
        return find(u) == find(v);
    }
};

int main() {
    int n = 6; // number of nodes
    DSU dsu(n);

    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 1}  // This edge forms a cycle
    };


    // 1->O
    // 2->O
    // if 1->2 then cycle appears

    for (auto [u, v] : edges) {
        if (dsu.isConnected(u, v)) {        // Cycle Detection, if Two edges are of same parent then we should not connect them both, To avoid Cycle
            cout << "Cycle detected between " << u << " and " << v << "\n";
        } else {
            dsu.unionSet(u, v);
        }
    }

    return 0;
}

// Initial sets:
// { 0 }
// { 1 }
// { 2 }
// { 3 }
// { 4 }
// { 5 }
// { 6 }

// After some unions:
// { 0 1 }
// { 2 3 }
// { 4 }
// { 5 6 }

// Are 1 and 3 in the same set? NO
// Are 5 and 6 in the same set? YES