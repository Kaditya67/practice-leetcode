// Problem: https://leetcode.com/problems/equal-row-and-column-pairs/
// Difficulty: Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> rowMap, colMap;
        int n = grid.size();

        for(int i = 0; i < n; i++) {
            string rowStr, colStr;
            for(int j = 0; j < n; j++) {
                rowStr += to_string(grid[i][j]) + ",";
                colStr += to_string(grid[j][i]) + ",";
            }
            rowMap[rowStr]++;
            colMap[colStr]++;
        }

        int result = 0;
        for(const auto& [rowStr, rowCount] : rowMap) {
            if(colMap.find(rowStr) != colMap.end()) {
                result += rowCount * colMap[rowStr];
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {
        {1, 2, 3},
        {2, 1, 3},
        {3, 3, 1}
    };
    cout << s.equalPairs(grid) << endl; // Example usage
    return 0;
}

