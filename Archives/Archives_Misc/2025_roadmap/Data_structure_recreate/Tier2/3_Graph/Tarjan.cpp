#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V, timer = 0;
    vector<vector<int>> adj;
    vector<int> tin, low;
    vector<bool> onStack;
    stack<int> st;
    vector<vector<int>> sccs;

public:
    Graph(int v) {
        V = v;
        adj.resize(V);
        tin.assign(V, -1);
        low.assign(V, -1);
        onStack.assign(V, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v); // directed
    }

    void dfs(int u) {
        tin[u] = low[u] = timer++;
        st.push(u);
        onStack[u] = true;

        for (int v : adj[u]) {
            if (tin[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (onStack[v]) {
                low[u] = min(low[u], tin[v]);
            }
        }

        // Found root of SCC
        if (tin[u] == low[u]) {
            vector<int> component;
            while (true) {
                int v = st.top(); st.pop();
                onStack[v] = false;
                component.push_back(v);
                if (v == u) break;
            }
            sccs.push_back(component);
        }
    }

    void tarjansSCC() {
        for (int i = 0; i < V; ++i)
            if (tin[i] == -1)
                dfs(i);

        cout << "Strongly Connected Components (Tarjan):\n";
        for (const auto& comp : sccs) {
            for (int node : comp)
                cout << node << " ";
            cout << "\n";
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

    g.tarjansSCC();

    return 0;
}
