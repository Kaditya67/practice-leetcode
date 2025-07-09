#include <bits/stdc++.h>
using namespace std;

class WordSearch {
public:
    bool dfs(vector<vector<char>>& board, string& word, int idx, int row, int col) {
        if (idx == word.size()) return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[idx])
            return false;

        char temp = board[row][col];
        board[row][col] = '#';  // mark visited

        // Explore all 4 directions
        bool found = dfs(board, word, idx + 1, row + 1, col) ||
                     dfs(board, word, idx + 1, row - 1, col) ||
                     dfs(board, word, idx + 1, row, col + 1) ||
                     dfs(board, word, idx + 1, row, col - 1);

        board[row][col] = temp;  // backtrack
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 0, i, j))
                        return true;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    WordSearch ws;
    cout << (ws.exist(board, word) ? "Found\n" : "Not Found\n");
}
