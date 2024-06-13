#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int row = 0;
        int col = matrix[0].size() - 1;

        while (row < matrix.size() && col >= 0) {
            cout<<matrix[row][col]<<endl;
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }

        return false;
    }
};

int main(){

    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    Solution sol;
    bool result = sol.searchMatrix(matrix,target);
    cout<<result<<endl;
    return 0;
}