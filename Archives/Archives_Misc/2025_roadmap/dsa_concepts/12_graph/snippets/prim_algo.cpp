#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> P; 

vector<int> primMST(int n, vector<vector<P>> &adj) {
    vector<int> parent(n, -1);  
    vector<int> key(n, INT_MAX); // Minimum edge weight
    vector<bool> inMST(n, false); // Tracks if node is in MST
    priority_queue<P, vector<P>, greater<P>> pq; // Min-heap {weight, node}

    key[0] = 0;  
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;  
        pq.pop();

        if (inMST[u]) continue;  
        inMST[u] = true; 

        for (auto &[v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u; 
            }
        }
    }

    return parent;  
}

int main() {
    int n = 5;
    vector<vector<P>> adj(n);

    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    vector<int> mst = primMST(n, adj);

    for (int i = 0; i < n; i++) {
        cout << "Parent of " << i << " is " << mst[i] << endl;
    }

    return 0;
}
