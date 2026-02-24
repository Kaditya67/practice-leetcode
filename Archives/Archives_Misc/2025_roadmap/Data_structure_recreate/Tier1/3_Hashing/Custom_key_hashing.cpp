#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


//! Template for custom key hashing
// struct pair_hash {
//     template <class T1, class T2>
//     size_t operator()(const pair<T1, T2> &p) const {
//         auto h1 = hash<T1>{}(p.first);
//         auto h2 = hash<T2>{}(p.second);
//         return h1 ^ h2; // XOR for combining
//     }
// };

//! Problem 149. Max Points on a Line
// https://leetcode.com/problems/max-points-on-a-line/

class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), result = 0;
        if (n <= 2) return n;

        for (int i = 0; i < n; ++i) {
            unordered_map<pair<int, int>, int, pair_hash> slopeMap;
            int same = 1, localMax = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    same++;  // Same point
                    continue;
                }

                int g = __gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Normalize slope to handle direction
                if (dx < 0) {
                    dx *= -1;
                    dy *= -1;
                }

                slopeMap[{dy, dx}]++;  // Store slope as (dy, dx)
                localMax = max(localMax, slopeMap[{dy, dx}]);
            }

            result = max(result, localMax + same);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}, {4, 1}, {5, 2}, {6, 3}};
    cout << "Maximum points on a line: " << sol.maxPoints(points) << endl;
    return 0;
}