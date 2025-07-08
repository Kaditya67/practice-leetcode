#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    // Adjacency List/ Matrix
    vector<vector<int>>adjList;
    int V;

public:
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

    return 0;
}
