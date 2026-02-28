/**
 * Problem: LeetCode 973 - K Closest Points to Origin
 * CodeChef: MAXDIFF (Maximum Weight Difference) - Custom Sort
 * ORDER: 09
 * ATOMIC TOPIC: PQ + Custom Struct Comparators
 *
 * DESCRIPTION:
 * Given an array of points where points[i] = [xi, yi] represents a point on the
 * X-Y plane and an integer k, return the k closest points to the origin (0, 0).
 *
 * CONSTRAINTS:
 * - 1 <= k <= points.length <= 10^4
 * - -10^4 <= xi, yi <= 10^4
 */

#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
  int x, y;
  long long distSq;

  Point(vector<int> &p) {
    x = p[0];
    y = p[1];
    distSq = (long long)x * x + (long long)y * y;
  }
};

struct ComparePoints {
  bool operator()(const Point &a, const Point &b) const {
    // Max-Heap: We want the LARGEST distance at the top so we can pop it.
    // In priority_queue, 'a < b' return true makes 'a' lower priority.
    return a.distSq < b.distSq;
  }
};

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    // We use a Max-Heap of size K.
    // The top of the heap will always be the FARTHEST point among the K closest
    // found so far.
    priority_queue<Point, vector<Point>, ComparePoints> pq;

    for (auto &p : points) {
      Point current(p);
      if (pq.size() < k) {
        pq.push(current);
      } else if (current.distSq < pq.top().distSq) {
        pq.pop();
        pq.push(current);
      }
    }

    vector<vector<int>> res;
    while (!pq.empty()) {
      res.push_back({pq.top().x, pq.top().y});
      pq.pop();
    }
    return res;
  }
};

int main() {
  Solution sol;

  // Test Case 1
  vector<vector<int>> points1 = {{1, 3}, {-2, 2}};
  int k1 = 1;
  vector<vector<int>> res1 = sol.kClosest(points1, k1);
  cout << "Test 1: [" << res1[0][0] << ", " << res1[0][1]
       << "] (Expected: [-2, 2])" << endl;

  return 0;
}
