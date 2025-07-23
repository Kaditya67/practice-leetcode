// Problem: https://leetcode.com/problems/rotting-oranges/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2)
                    q.push({i, j}); // We will start rotting from here
                else if (grid[i][j] == 1)
                    fresh++;    // Fresh Oranges
            }
        }

        if (fresh == 0) return 0;

        int minutes = 0;
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front(); q.pop();

                for (auto& [dr, dc] : directions) {
                    int nr = r + dr, nc = c + dc;

                    // If it's a fresh orange, rot it
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;   // Rot
                        fresh--;
                        q.push({nr, nc});       // New Rotting start from here
                        rotted = true;
                    }
                }
            }
            if (rotted) minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
};

int main() {
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    Solution s;
    cout << s.orangesRotting(grid) << endl;
    return 0;
}
