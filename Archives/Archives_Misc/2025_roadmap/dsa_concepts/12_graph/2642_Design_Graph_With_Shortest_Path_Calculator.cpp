class Graph {
    public:
        vector<vector<pair<int,int>>> adj;
        int N = 0;
        Graph(int n, vector<vector<int>>& edges) {
            N = n;
            adj = vector<vector<pair<int,int>>>(n, vector<pair<int,int>>());
            for(auto& c : edges){
                adj[c[0]].push_back({c[1], c[2]});
            }
        }
        
        void addEdge(vector<int> edge) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        
        int shortestPath(int node1, int node2) {
            vector<int>result(N,INT_MAX);
            set<pair<int,int>> st;
    
            result[node1]=0;
            st.insert({0,node1});
    
            
            while(!st.empty()){
                auto &it = *st.begin();
                int dist = it.first;
                int node = it.second;
                st.erase(it);
    
                for(auto &vec:adj[node]){
                    int adjNode = vec.first;
                    int D = vec.second;
    
                    if(dist+D < result[adjNode]){
                        if(result[adjNode]!=INT_MAX){
                            st.erase({result[adjNode],adjNode});
                        }
                        result[adjNode] = dist+D;
                        st.insert({dist+D,adjNode});
                    }
                }
            }
            return result[node2]==INT_MAX ? -1 : result[node2];
    
        }
    };
    
    /**
     * Your Graph object will be instantiated and called as such:
     * Graph* obj = new Graph(n, edges);
     * obj->addEdge(edge);
     * int param_2 = obj->shortestPath(node1,node2);
     */