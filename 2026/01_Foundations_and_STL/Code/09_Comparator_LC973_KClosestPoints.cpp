/**
 * PROBLEM: LeetCode 973 - K Closest Points to Origin
 * ORDER: 09
 * ATOMIC TOPIC: PQ + Custom Struct Comparators
 * 
 * DESCRIPTION:
 * Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane 
 * and an integer k, return the k closest points to the origin (0, 0).
 * 
 * CONSTRAINTS:
 * - 1 <= k <= points.length <= 10^4
 * - -10^4 <= xi, yi <= 10^4
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // TODO: Implement PQ with Custom Comparator
        return {};
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<vector<int>> points1 = {{1,3},{-2,2}};
    int k1 = 1;
    vector<vector<int>> res1 = sol.kClosest(points1, k1);
    cout << "Test 1: [" << res1[0][0] << ", " << res1[0][1] << "] (Expected: [-2, 2])" << endl;

    return 0;
}
