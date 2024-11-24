/*
 * @lc app=leetcode id=1975 lang=cpp
 *
 * [1975] Maximum Matrix Sum
 */

// @lc code=start
class Solution {
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        long long sum = 0;
        int negCount = 0;
        int smallerNum = INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += abs(matrix[i][j]);
                smallerNum = min(smallerNum,abs(matrix[i][j]));
                negCount += matrix[i][j] < 0 ? 1 : 0;
            }
        }
        if(negCount%2 != 0){
            sum=sum-2*smallerNum;
        }
        return sum;
    }
};
// @lc code=end

