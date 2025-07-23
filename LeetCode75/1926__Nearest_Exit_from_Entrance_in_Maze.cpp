// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
// Tag: BFS
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';   // Visisted
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            steps++;

            for (int i = 0; i < size; ++i) {        
                auto [r, c] = q.front();
                q.pop();

                for (auto& [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] == '.') {    // If it's a place
                        if (nr == 0 || nr == m-1 || nc == 0 || nc == n-1)
                            return steps;   // Return exit

                        maze[nr][nc] = '+'; // Mark visited
                        q.push({nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<char>> maze = {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    vector<int> entrance = {1, 2};
    cout << s.nearestExit(maze, entrance) << endl;  // 1
    return 0;
}
