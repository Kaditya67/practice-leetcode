#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Kosaraju {
private:
    int n;
    vector<vector<int>> adj, revAdj;
    vector<bool> visited;
    stack<int> order;
    vector<vector<int>> sccs;  

    void dfs1(int node) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs1(neighbor);
            }
        }
        order.push(node);
    }

    void dfs2(int node, vector<int> &component) {
        visited[node] = true;
        component.push_back(node);
        for (int neighbor : revAdj[node]) {
            if (!visited[neighbor]) {
                dfs2(neighbor, component);
            }
        }
    }

public:
    Kosaraju(int nodes) : n(nodes), adj(nodes), revAdj(nodes), visited(nodes, false) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    vector<vector<int>> findSCCs() {
        visited.assign(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs1(i);
            }
        }

        visited.assign(n, false);
        while (!order.empty()) {
            int node = order.top();
            order.pop();
            if (!visited[node]) {
                vector<int> component;
                dfs2(node, component);
                sccs.push_back(component);
            }
        }

        return sccs;  
    }
};

int main() {
    int n = 5; 
    Kosaraju graph(n);

    graph.addEdge(0, 2);
    graph.addEdge(2, 1);
    graph.addEdge(1, 0);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);

    vector<vector<int>> sccs = graph.findSCCs();

    for (int i = 0; i < sccs.size(); i++) {
        cout << "SCC " << i + 1 << ": ";
        for (int node : sccs[i]) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}
