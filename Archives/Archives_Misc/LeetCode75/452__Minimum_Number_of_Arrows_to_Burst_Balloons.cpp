// Problem: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int lastArrowPos = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > lastArrowPos) {
                arrows++;
                lastArrowPos = points[i][1]; // Move arrow to new balloon's end
            }
        }

        return arrows;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    cout << s.findMinArrowShots(points) << endl;
    return 0;
}



// Greedy approach
// Sort the intervals by their end points
// Initialize arrow count to 1 and last arrow position to the end of the first interval
// Iterate over the intervals, if the current interval's start point is > last arrow pos, increment arrow count and update last arrow pos
// Return the arrow count

// Dry Run Example:
// i = 1 → balloon = [2,8]
// start = 2, which is ≤ 6 (lastArrowPos)
// This balloon overlaps with previous one → current arrow bursts it
// ➤ No new arrow needed

// i = 2 → balloon = [7,12]
// start = 7, which is > 6
// No overlap → Need a new arrow
// Shoot new arrow at end = 12

// Update:
// arrows = 2
// lastArrowPos = 12


// i = 3 → balloon = [10,16]
// start = 10, which is ≤ 12
// Overlaps with previous → current arrow bursts it
// ➤ No new arrow needed

// Final Answer:
// arrows = 2