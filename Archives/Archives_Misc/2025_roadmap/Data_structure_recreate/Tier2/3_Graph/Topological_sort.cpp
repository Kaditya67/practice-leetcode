#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjList;

public:
    Graph(int v) {
        V = v;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Directed edge u → v
    }

    bool topoSortDFSUtil(int node, vector<bool>& visited, vector<bool>& recStack, stack<int>& st) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                if (!topoSortDFSUtil(neighbor, visited, recStack, st))
                    return false;
            } else if (recStack[neighbor]) {
                // Cycle detected
                return false;
            }
        }

        recStack[node] = false;
        st.push(node);
        return true;
    }

    // It tracks which nodes are currently in the recursive call stack
    // If during DFS, you visit a neighbor that is already in the recStack, that means:
    // 🔁 “You found a back-edge → there's a cycle!”
    
    void topoSortDFS() {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        stack<int> st;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (!topoSortDFSUtil(i, visited, recStack, st)) {
                    cout << "Cycle detected! No topological sort exists.\n";
                    return;
                }
            }
        }

        cout << "Topological Sort (DFS-based): ";
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
};

// If there's an edge u → v, then u comes before v in the order. ---> Topological Sorting
int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.topoSortDFS();

    return 0;
}
