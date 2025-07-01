#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
    }
};

struct Point {
    int x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

struct point_hash {
    size_t operator()(const Point& p) const {
        return hash<int>{}(p.x) ^ (hash<int>{}(p.y) << 1);
    }
};

int main() {
    // Basic operations
    unordered_set<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(10); // No duplicates
    s.erase(5);
    cout << "Find 10: " << (s.count(10) ? "Yes" : "No") << "\n";

    // Remove duplicates from array
    vector<int> arr = {1, 2, 2, 3, 4, 1};
    unordered_set<int> unique(arr.begin(), arr.end());
    cout << "Unique values: ";
    for (int x : unique) cout << x << " "; cout << "\n";

    // Two-sum style: Find pair that sums to K
    int target = 6;
    unordered_set<int> seen;
    vector<int> nums = {1, 4, 2, 5};
    for (int num : nums) {
        if (seen.count(target - num)) {     // If same difference already exists then we have a pair
            cout << "Pair found: " << num << " + " << (target - num) << "\n";
        }
        seen.insert(num);
    }

    // Longest Consecutive Sequence (LC #128)
    unordered_set<int> seqSet = {100, 4, 200, 1, 3, 2};
    int maxLen = 0;
    for (int x : seqSet) {
        if (!seqSet.count(x - 1)) {
            int len = 1, current = x;
            while (seqSet.count(current + 1)) {
                current++;
                len++;
            }
            maxLen = max(maxLen, len);
        }
    }
    cout << "Longest consecutive sequence: " << maxLen << "\n";

    // unordered_set of pairs (using custom hash)
    unordered_set<pair<int, int>, pair_hash> slopeSet;
    slopeSet.insert({1, 2});
    slopeSet.insert({2, 1});
    slopeSet.insert({1, 2}); // No duplicate

    cout << "Pairs in set: ";
    for (auto [a, b] : slopeSet) cout << "{" << a << "," << b << "} "; cout << "\n";

    // unordered_set of custom struct (with hash)
    unordered_set<Point, point_hash> pointSet;
    pointSet.insert({1, 2});
    pointSet.insert({3, 4});
    pointSet.insert({1, 2}); // No duplicate
    cout << "Custom Points: ";
    for (auto p : pointSet) cout << "(" << p.x << "," << p.y << ") "; cout << "\n";

    return 0;
}
