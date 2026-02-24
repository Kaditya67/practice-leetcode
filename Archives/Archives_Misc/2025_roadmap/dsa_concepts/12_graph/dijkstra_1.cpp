class Solution {
    public:
      vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
          int n = adj.size();
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
          vector<int> result(n, INT_MAX);
      
          result[src] = 0;
          pq.push({0, src});
      
          while (!pq.empty()) {
              int dist = pq.top().first;
              int node = pq.top().second;
              pq.pop();
      
              for (auto &vec : adj[node]) {
                  int adjNode = vec.first;
                  int D = vec.second;
      
                  if (dist + D < result[adjNode]) { 
                      result[adjNode] = dist + D;    
                      pq.push({dist + D, adjNode});
                  }
              }
          }
          return result;
      }
  };