#include <iostream>
#include <vector>

using namespace std;

vector<int> printSpiralMatrix(vector<vector<int>>& matrix) {
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();

    int startRow = 0;
    int startCol = 0;
    int endRow = row - 1;
    int endCol = col - 1;

    int count = 0;    // count for each element
    int total = row * col;

    while (count < total) {
        // Traverse right
        for (int i = startCol; i <= endCol && count < total; i++) {
            ans.push_back(matrix[startRow][i]);
            count++;
        }
        startRow++;

        // Traverse down
        for (int i = startRow; i <= endRow && count < total; i++) {
            ans.push_back(matrix[i][endCol]);
            count++;
        }
        endCol--;

        // Traverse left
        for (int i = endCol; i >= startCol && count < total; i--) {
            ans.push_back(matrix[endRow][i]);
            count++;
        }
        endRow--;

        // Traverse up
        for (int i = endRow; i >= startRow && count < total; i--) {
            ans.push_back(matrix[i][startCol]);
            count++;
        }
        startCol++;
    }

    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> ans = printSpiralMatrix(matrix);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
