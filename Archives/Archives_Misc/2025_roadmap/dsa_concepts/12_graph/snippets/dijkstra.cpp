#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <set>

using namespace std;

typedef pair<int, int> P;

vector<int> dijkstra(int start, int n, vector<vector<P>> &adj) {
    vector<int> dist(n, INT_MAX);
    priority_queue<P, vector<P>, greater<P>> pq; 

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;   
        int node = pq.top().second; 
        pq.pop();

        // If current distance is greater than already found, skip
        if (d > dist[node]) continue;

        for (P edge : adj[node]) { 
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    return dist;
}

// vector<int> dijkstra(int start, int n, vector<vector<P>> &adj) {
//     vector<int> dist(n, INT_MAX);
//     set<P> st;

//     dist[start] = 0;
//     st.insert({0, start});

//     while (!st.empty()) {
//         auto &it = *st.begin();
//         int d = it.first;  
//         int node = it.second; 
//         st.erase(it);

//         // If current distance is greater than already found, skip
//         if (d > dist[node]) continue;

//         for (P edge : adj[node]) { 
//             int neighbor = edge.first;
//             int weight = edge.second;

//             if (dist[node] + weight < dist[neighbor]) {

//                 if(dist[neighbor] != INT_MAX) {
//                     st.erase({dist[neighbor], neighbor});
//                 }

//                 dist[neighbor] = dist[node] + weight;
//                 st.insert({dist[neighbor], neighbor});
//             }
//         }
//     }
//     return dist;
// }

int main() {
    int n = 6; 
    vector<vector<P>> adj(n); 

    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[1].push_back({0, 4});
    adj[1].push_back({3, 1});
    adj[1].push_back({4, 3});
    adj[2].push_back({0, 1});
    adj[2].push_back({4, 2});
    adj[3].push_back({1, 1});
    adj[3].push_back({5, 5});
    adj[4].push_back({1, 3});
    adj[4].push_back({2, 2});
    adj[4].push_back({5, 1});
    adj[5].push_back({3, 5});
    adj[5].push_back({4, 1});

    int start = 0; 
    vector<int> shortest_paths = dijkstra(start, n, adj);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To node " << i << " : " << shortest_paths[i] << "\n";
    }

    return 0;
}
