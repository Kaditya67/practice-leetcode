#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    // Adjacency List/ Matrix
    vector<vector<int>>adjList;
    int V;

    Graph(int vertices){
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v, bool directed = false){
        adjList[u].push_back(v);
        if (!directed) {
            adjList[v].push_back(u);  
        }
    }

    void printGraph(){
        for(int i=0;i<V;i++){
            cout << i << ": ";
            for(int neighbor : adjList[i]){
                cout<< neighbor << " ";
            }
            cout<<endl;
        }
    }
};


void bfs(Graph& graph, int start, int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(start);
    visited[start]=true;

    cout << "BFS starting from node " << start << ": ";
    while(!q.empty()){
        int node =  q.front();
        q.pop();
        cout << node << " ";

        for(int neighbor: graph.adjList[node]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout<<endl;
}

void dfsUtil(int node, vector<vector<int>> &adjList, vector<bool> &visited){
    visited[node] = true;
    cout << node << " ";

    for(int neighbor:adjList[node]){
        if(!visited[neighbor]){
            dfsUtil(neighbor, adjList, visited);
        }
    }
}

void dfs(int start, vector<vector<int>> &adjList,int V){
    vector<bool> visited(V, false);
    cout << "DFS traversal starting from node " << start << ": ";
    dfsUtil(start,adjList, visited);
    cout<<endl;
}


int main() {
    int V = 6;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    g.printGraph();
    bfs(g,0,V);
    dfs(0,g.adjList,V);
    return 0;
}
