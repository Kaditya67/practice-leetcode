#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    vector<vector<int>> revAdj;

public:
    Graph(int v) {
        V = v;
        adj.resize(V);
        revAdj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);       // Original edge
        revAdj[v].push_back(u);    // Reverse edge
    }

    void dfs1(int u, vector<bool>& visited, stack<int>& st) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v])
                dfs1(v, visited, st);
        }
        st.push(u);
    }

    void dfs2(int u, vector<bool>& visited, vector<int>& component) {
        visited[u] = true;
        component.push_back(u);
        for (int v : revAdj[u]) {
            if (!visited[v])
                dfs2(v, visited, component);
        }
    }

    void kosarajuSCC() {
        vector<bool> visited(V, false);
        stack<int> st;

        // Step 1: Fill finishing times
        for (int i = 0; i < V; ++i) {
            if (!visited[i])
                dfs1(i, visited, st);
        }

        // Step 2: DFS on transposed graph
        fill(visited.begin(), visited.end(), false);

        cout << "Strongly Connected Components (Kosaraju):\n";
        while (!st.empty()) {
            int u = st.top(); st.pop();
            if (!visited[u]) {
                vector<int> component;
                dfs2(u, visited, component);

                for (int node : component)
                    cout << node << " ";
                cout << "\n";
            }
        }
    }
};

int main() {
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);
    g.addEdge(6, 5);
    g.addEdge(6, 7);

    g.kosarajuSCC();

    return 0;
}

// Feature	            Kosaraju	        Tarjan
// DFS calls	        2	                1
// Stack used	        Global topo stack	Recursion + onStack
// Transpose needed?	✅ Yes	           ❌ No
// Easier to implement?	✅ Yes (sometimes)  Slightly more tricky
// Complexity	        O(V + E)	        O(V + E)
