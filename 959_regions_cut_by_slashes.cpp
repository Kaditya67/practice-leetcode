#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void numberOfRegions(vector<vector<int>>& matrix, int i, int j) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == 1) {
            return;
        }

        matrix[i][j] = 1; // Mark as visited
        numberOfRegions(matrix, i + 1, j);
        numberOfRegions(matrix, i - 1, j);
        numberOfRegions(matrix, i, j + 1);
        numberOfRegions(matrix, i, j - 1);
    }

    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int regionCount = 0;

        vector<vector<int>> matrix(rows * 3, vector<int>(cols * 3, 0)); // Initialize to 0

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '/') {
                    matrix[i * 3][j * 3 + 2] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') { // Corrected condition
                    matrix[i * 3][j * 3] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        for (int i = 0; i < rows * 3; i++) {
            for (int j = 0; j < cols * 3; j++) {
                if (matrix[i][j] == 0) {
                    // Applying DFS
                    numberOfRegions(matrix, i, j);
                    regionCount++;
                }
            }
        }
        return regionCount;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<string> grid1 = {
        " /",
        "/ "
    };
    cout << "Test Case 1: " << solution.regionsBySlashes(grid1) << endl; // Expected output: 2

    // Test case 2
    vector<string> grid2 = {
        " /",
        "  "
    };
    cout << "Test Case 2: " << solution.regionsBySlashes(grid2) << endl; // Expected output: 1

    // Test case 3
    vector<string> grid3 = {
        "\\/",
        "/\\"
    };
    cout << "Test Case 3: " << solution.regionsBySlashes(grid3) << endl; // Expected output: 4

    // Test case 4
    vector<string> grid4 = {
        "/\\",
        "\\/"
    };
    cout << "Test Case 4: " << solution.regionsBySlashes(grid4) << endl; // Expected output: 5

    // Test case 5
    vector<string> grid5 = {
        "//",
        "/ "
    };
    cout << "Test Case 5: " << solution.regionsBySlashes(grid5) << endl; // Expected output: 3

    return 0;
}
