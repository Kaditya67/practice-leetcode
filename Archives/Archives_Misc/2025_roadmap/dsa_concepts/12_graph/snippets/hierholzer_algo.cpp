#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Hierholzer {
private:
    int n;
    vector<vector<int>> adj;
    vector<int> circuit;  

    void dfs(int node) {
        while (!adj[node].empty()) {
            int next = adj[node].back();
            adj[node].pop_back();

            // Remove the edge from the other vertex as well
            auto it = find(adj[next].begin(), adj[next].end(), node);
            if (it != adj[next].end()) adj[next].erase(it);

            dfs(next);
        }
        circuit.push_back(node);
    }

public:
    Hierholzer(int nodes) : n(nodes), adj(nodes) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> findEulerianPath() {
        int start = -1, oddCount = 0;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() % 2 == 1) {
                oddCount++;
                start = i;  
            }
        }

        if (oddCount != 0 && oddCount != 2) return {}; 

        if (start == -1) start = 0; 

        dfs(start);
        reverse(circuit.begin(), circuit.end());

        return circuit.size() == edgesCount() + 1 ? circuit : vector<int>();  
    }

    int edgesCount() {
        int count = 0;
        for (int i = 0; i < n; i++) count += adj[i].size();
        return count / 2;
    }
};

int main() {
    int n = 6;
    Hierholzer graph(n);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 1);

    vector<int> path = graph.findEulerianPath();

    if (path.empty()) {
        cout << "No Eulerian path exists.\n";
    } else {
        cout << "Eulerian path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
