#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> adjList;     // 0 → 1 (4)  --> 0 -> {1,4}  // {node, weight}

    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight, bool directed = false) {
        adjList[u].push_back({v, weight});
        if (!directed) {
            adjList[v].push_back({u, weight});
        }
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (auto [neighbor, weight] : adjList[i]) {
                cout << "(" << neighbor << ", " << weight << ") ";
            }
            cout << endl;
        }
    }
};

void dijkstra(int src,vector<vector<pair<int, int>>> &adjList,int V) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;  // From Src to Src
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;   // {distance, node}
    pq.push({0, src});
    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();

        //! When you push a node u into the priority_queue, you might do it multiple times with different distances:
        // You’d process node u again even if you've already found a better path — meaning:
        // - Unnecessary loops over adjList[u]
        // - Wasted CPU cycles
        // - More edge relaxations

        if (d > dist[u]) continue;      // For the same node, if we have better value --> skip

        for(auto [v,w]: adjList[u]){
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "To " << i << ": " << dist[i] << "\n";
    }
}

// dist[u] = shortest distance to reach u (already known)
// w = cost to go from u → v
// dist[v] = current known shortest distance to v

int main() {
    int V = 6;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, 1);

    g.printGraph();

    dijkstra(0,g.adjList,V);  // Start from node 0

    return 0;
}
