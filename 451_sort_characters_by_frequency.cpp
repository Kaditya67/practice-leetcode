class Solution {
public:
    typedef pair<int,int> P;
    struct comp {
        bool operator()(const P &p1, const P &p2) {
            return p1.second < p2.second; // Max-Heap: higher frequency comes first
        }
    };
    string frequencySort(string s) {
        priority_queue<P, vector<P>, comp> pq;

        unordered_map<char, int> mp;

        for(char &ch:s){
            mp[ch]++;
        }

        for(auto &it:mp){
            pq.push({it.first,it.second});
        }

        string result = "";
        while(!pq.empty()) {
            P temp = pq.top();
            pq.pop();
            
            result += string(temp.second, temp.first);
        }
        return result;
    }
};