#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;

        sort(intervals.begin(), intervals.end());

        merged.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {


            // Update thr irghtmost value of the previous interval
            
            if(intervals[i][0] <= merged.back()[1]) {       // If the next intervals 0th index value is less than or equal to the previous one then it means there is overlap
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);  // change the previous value to the max of the two
            } else {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};

int main(){
    Solution s;

    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> merged = s.merge(intervals);

    for(const auto& interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
