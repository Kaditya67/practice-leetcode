#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class EulerianPath {
private:
    int n;
    vector<vector<int>> adj;
    vector<int> inDegree, outDegree;
    stack<int> path;
    vector<int> circuit;  

    void dfs(int node) {
        while (!adj[node].empty()) {
            int next = adj[node].back();
            adj[node].pop_back();
            dfs(next);
        }
        circuit.push_back(node);
    }

public:
    EulerianPath(int nodes) : n(nodes), adj(nodes), inDegree(nodes, 0), outDegree(nodes, 0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        outDegree[u]++;
        inDegree[v]++;
    }

    vector<int> findEulerianPath() {
        int start = 0, oddIn = 0, oddOut = 0;

        for (int i = 0; i < n; i++) {
            if (outDegree[i] - inDegree[i] == 1) {
                oddOut++, start = i;
            } else if (inDegree[i] - outDegree[i] == 1) {
                oddIn++;
            }
        }

        if (oddOut != oddIn || oddOut > 1) return {};  

        dfs(start);
        reverse(circuit.begin(), circuit.end());

        return circuit.size() == edgesCount() + 1 ? circuit : vector<int>();  
    }

    int edgesCount() {
        int count = 0;
        for (int i = 0; i < n; i++) count += outDegree[i];
        return count;
    }
};

int main() {
    int n = 5;
    EulerianPath graph(n);

    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 1);
    graph.addEdge(0, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 0);

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
