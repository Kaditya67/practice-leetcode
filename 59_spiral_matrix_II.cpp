// vector<vector<int>>: This declares result as a 2D vector (a vector of vectors) where each element of the outer vector is itself a vector of integers.
// result(n, vector<int>(n)): This initializes the 2D vector with n rows, where each row is a vector of n integers.
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int k = 1;
        int top = 0, bottom = n - 1, left = 0, right = n - 1;

        while (k <= n * n) {
            // Fill the top row from left to right
            for (int i = left; i <= right; i++) {
                result[top][i] = k++;
            }
            top++; // Move down one row

            // Fill the rightmost column from top to bottom
            for (int i = top; i <= bottom; i++) {
                result[i][right] = k++;
            }
            right--; // Move left one column

            // Fill the bottom row from right to left
            for (int i = right; i >= left; i--) {
                result[bottom][i] = k++;
            }
            bottom--; // Move up one row

            // Fill the leftmost column from bottom to top
            for (int i = bottom; i >= top; i--) {
                result[i][left] = k++;
            }
            left++; // Move right one column
        }
        return result;
    }
};


int main(){
    Solution solution;

    int n = 3;

    vector<vector<int>> result = solution.generateMatrix(n);

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}