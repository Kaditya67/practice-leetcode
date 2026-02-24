#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int count = 0;

    void solve(int row, int n, vector<int>& col, vector<int>& diag, vector<int>& antiDiag) {
        if (row == n) {
            count++;
            return;
        }

        for (int c = 0; c < n; ++c) {
            int d = row - c + n - 1;     // main diagonal index
            int ad = row + c;            // anti-diagonal index

            if (col[c] || diag[d] || antiDiag[ad])
                continue;

            col[c] = diag[d] = antiDiag[ad] = 1;
            solve(row + 1, n, col, diag, antiDiag);
            col[c] = diag[d] = antiDiag[ad] = 0;
        }
    }

    int totalNQueens(int n) {
        count = 0;
        vector<int> col(n, 0);
        vector<int> diag(2 * n - 1, 0);
        vector<int> antiDiag(2 * n - 1, 0);
        solve(0, n, col, diag, antiDiag);
        return count;
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    int result = solution.totalNQueens(n);
    cout << "Total solutions for " << n << "-Queens: " << result << endl;

    return 0;
}
