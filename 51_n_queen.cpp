#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;

    bool isValid(vector<string>& board, int row, int col) {
        // Check vertical column
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(vector<string>& board, int row) {
        if (row == board.size()) {
            result.push_back(board);
            return;
        }

        for (int i = 0; i < board.size(); i++) {
            if (isValid(board, row, i)) {
                board[row][i] = 'Q';         // place queen
                solve(board, row + 1);       // move to next row
                board[row][i] = '.';         // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        if (n == 0)
            return {};
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return result;
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<vector<string>> solutions = solution.solveNQueens(n);

    cout << "Total solutions: " << solutions.size() << "\n\n";

    for (int i = 0; i < solutions.size(); ++i) {
        cout << "Solution " << i + 1 << ":\n";
        for (const string& row : solutions[i]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
