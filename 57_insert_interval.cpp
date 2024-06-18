#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
    const int n = intervals.size();
    vector<vector<int>> ans;
    int i = 0;

    while (i < n && intervals[i][1] < newInterval[0])
      ans.push_back(intervals[i++]);
    // Merge overlapping intervals.
    while (i < n && intervals[i][0] <= newInterval[1]) {
      newInterval[0] = min(newInterval[0], intervals[i][0]);
      newInterval[1] = max(newInterval[1], intervals[i][1]);
      ++i;
    }

    ans.push_back(newInterval);
    while (i < n)
      ans.push_back(intervals[i++]);

    return ans;

  }

}; 

int main(){

    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> ans = Solution().insert(intervals, newInterval);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
    
