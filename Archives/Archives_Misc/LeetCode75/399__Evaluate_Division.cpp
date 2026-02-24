// https://leetcode.com/problems/evaluate-division/
// Medium

#include <bits/stdc++.h>
using namespace std;    

class Solution {
public:
    double dfs(const string& curr, const string& target, unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string>& visited) {
        if (graph.find(curr) == graph.end()) return -1.0;
        if (curr == target) return 1.0;

        visited.insert(curr);

        for (auto& [neighbor, weight] : graph[curr]) {
            if (visited.count(neighbor)) continue;
            double result = dfs(neighbor, target, graph, visited);
            if (result != -1.0) {
                return result * weight;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        // Step 1: Build graph
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        vector<double> results;

        // Step 2: Handle queries
        for (auto& query : queries) {
            string start = query[0], end = query[1];
            unordered_set<string> visited;

            double result = dfs(start, end, graph, visited);
            results.push_back(result);
        }

        return results;
    }
};


int main() {
    Solution s;
    vector<vector<string>> equations = {{"a","b"},{"b","c"},{"bc","cd"}};
    vector<double> values = {1.5,2.5,5.4};
    vector<vector<string>> queries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
    vector<double> results = s.calcEquation(equations, values, queries);
    for (auto& result : results) {
        cout << result << endl;
    }
    return 0;
}
