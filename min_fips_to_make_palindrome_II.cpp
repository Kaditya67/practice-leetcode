#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Helper function to count the number of flips needed to make a vector palindromic
        auto countFlipsForPalindrome = [](const vector<int>& vec) {
            int len = vec.size();
            int flips = 0;
            for (int i = 0; i < len / 2; ++i) {
                if (vec[i] != vec[len - i - 1]) {
                    flips++;
                }
            }
            return flips;
        };

        // Calculate flips needed for each row to be palindromic
        int rowFlips = 0;
        cout << "Row flips:" << endl;
        for (int i = 0; i < m; ++i) {
            vector<int> row = grid[i];
            int flips = countFlipsForPalindrome(row);
            rowFlips += flips;
            cout << "Row " << i << ": ";
            for (int val : row) cout << val << " ";
            cout << " - Flips needed: " << flips << endl;
        }

        // Calculate flips needed for each column to be palindromic
        int colFlips = 0;
        cout << "Column flips:" << endl;
        for (int j = 0; j < n; ++j) {
            vector<int> col(m);
            for (int i = 0; i < m; ++i) {
                col[i] = grid[i][j];
            }
            int flips = countFlipsForPalindrome(col);
            colFlips += flips;
            cout << "Column " << j << ": ";
            for (int val : col) cout << val << " ";
            cout << " - Flips needed: " << flips << endl;
        }

        // Count total number of 1s
        int totalOnes = 0;
        cout << "Total number of 1s:" << endl;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    totalOnes++;
                }
            }
        }
        cout << "Total number of 1s: " << totalOnes << endl;

        // Calculate the number of flips needed to make totalOnes divisible by 4
        int remainder = totalOnes % 4;
        int extraFlips = (remainder == 0) ? 0 : (4 - remainder);
        cout << "Extra flips needed to make total number of 1s divisible by 4: " << extraFlips << endl;

        // Return the total flips needed for rows and columns plus the additional flips
        int totalFlips = rowFlips + colFlips + extraFlips;
        cout << "Total flips needed: " << totalFlips << endl;

        return totalFlips;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> grid1 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    vector<vector<int>> grid2 = {
        {0, 1},
        {0, 1},
        {0, 0}
    };

    vector<vector<int>> grid3 = {
        {1},
        {1}
    };

    cout << "Test Case 1:" << endl;
    cout << "Input grid:" << endl;
    for (const auto& row : grid1) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    cout << "Output: " << solution.minFlips(grid1) << endl << endl;

    cout << "Test Case 2:" << endl;
    cout << "Input grid:" << endl;
    for (const auto& row : grid2) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    cout << "Output: " << solution.minFlips(grid2) << endl << endl;

    cout << "Test Case 3:" << endl;
    cout << "Input grid:" << endl;
    for (const auto& row : grid3) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    cout << "Output: " << solution.minFlips(grid3) << endl;

    return 0;
}
