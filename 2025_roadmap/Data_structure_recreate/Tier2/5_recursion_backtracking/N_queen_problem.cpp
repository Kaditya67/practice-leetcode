#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<int>& queens) {
    for (int r = 0; r < row; r++) {
        int c = queens[r];
        if (c == col || abs(row - r) == abs(col - c)) 
            return false;
    }
    return true;
}

void solveNQueens(int row, int n, vector<int>& queens, vector<vector<string>>& solutions) {
    if (row == n) {
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            board[i][queens[i]] = 'Q';
        }
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, queens)) {
            queens[row] = col;
            solveNQueens(row + 1, n, queens, solutions);
            // no explicit backtrack needed since we overwrite queens[row]
        }
    }
}

int main() {
    int n = 4;
    vector<int> queens(n, -1);
    vector<vector<string>> solutions;

    solveNQueens(0, n, queens, solutions);

    for (auto& board : solutions) {
        for (auto& row : board) cout << row << "\n";
        cout << "\n";
    }
}
