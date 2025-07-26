// Problem: https://leetcode.com/problems/non-overlapping-intervals/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

// Greedy approach
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prevEnd) {
                count++;
            }else {
                // No overlap → update end
                prevEnd = intervals[i][1];
            }
        }

        return count;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << solution.eraseOverlapIntervals(intervals) << endl;
    return 0;
}

