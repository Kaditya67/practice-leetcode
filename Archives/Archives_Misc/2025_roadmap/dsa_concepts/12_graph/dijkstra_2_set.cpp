class Solution {
    public:
      vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        vector<int>result(n, INT_MAX);
        // set
        set<pair<int, int>>st;

        result[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            auto &it = *st.begin(); // with * we get the element not the address
            int node = it.second;
            int dist = it.first;

            st.erase(it);
            for (auto &vec : adj[node]) {
                int adjNode = vec.first;
                int D = vec.second;

                if(dist + D < result[adjNode]) {
                    if(result[adjNode] != INT_MAX) {
                        st.erase({result[adjNode], adjNode});
                    }
                    result[adjNode] = dist + D;
                    st.insert({dist + D, adjNode});
                }
            }
        }
        return result;
      }
    };