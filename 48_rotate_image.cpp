#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int row=matrix.size();
        int col=matrix[0].size();
       
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
int main(){

    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s.rotate(matrix);

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }   

    return 0;
}