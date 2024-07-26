#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Initialize result matrix with dimensions swapped
        vector<vector<int>> result(n, vector<int>(m));

        // Perform transpose
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[j][i] = matrix[i][j];
            }
        }

        return result;
    }
};

int main() {
    // Example usage
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution sol;
    vector<vector<int>> transposed = sol.transpose(matrix);

    // Print transposed matrix
    cout << "Transposed Matrix:" << endl;
    for (const auto& row : transposed) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
