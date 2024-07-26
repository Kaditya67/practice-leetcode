#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int count = 0;

        vector<int> row_count(row, 0);
        vector<int> col_count(col, 0);

        // Count the number of 1's in each row and column
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (mat[i][j] == 1) {
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }

        // Check for special positions
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (mat[i][j] == 1 && row_count[i] == 1 && col_count[j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    // Example usage
    vector<vector<int>> mat = {
        {1, 0, 0},
        {0, 0, 1},
        {1, 0, 0}
    };

    Solution sol;
    int result = sol.numSpecial(mat);

    // Print result
    cout << "Number of special positions: " << result << endl;

    return 0;
}
