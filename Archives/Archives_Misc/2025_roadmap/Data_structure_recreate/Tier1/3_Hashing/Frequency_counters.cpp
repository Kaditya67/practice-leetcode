#include <iostream>
#include <set>
#include <map>
using namespace std;

// Struct representing a 2D Point
struct Point {
    int x, y;

    // Optional: Equality operator for manual comparisons
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// Comparator for descending order (used in map)
struct DescendingCompare {
    bool operator()(const Point& a, const Point& b) const {
        if (a.x != b.x) return a.x > b.x;
        return a.y > b.y;
    }
};

// Comparator for ascending order (used in set)
struct ComparePoint {
    bool operator()(const Point& a, const Point& b) const {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    }
};

int main() {
    // ----- Custom Ordered Map -----
    map<Point, int, DescendingCompare> freq;

    freq[{1, 2}] = 5;
    freq[{3, 4}] = 2;
    freq[{2, 1}] = 7;
    freq[{3, 2}] = 6;

    cout << "Descending Ordered Map:\n";
    for (auto& [p, val] : freq) {
        cout << "(" << p.x << ", " << p.y << ") → " << val << endl;
    }

    cout << "\n";

    // ----- Custom Ordered Set -----
    set<Point, ComparePoint> pointSet;

    pointSet.insert({2, 3});
    pointSet.insert({1, 5});
    pointSet.insert({2, 3});  // Duplicate (ignored)
    pointSet.insert({3, 2});

    cout << "Ascending Ordered Set:\n";
    for (const auto& p : pointSet) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    cout << "\n";

    // ----- Manual Equality Check -----
    Point a = {2, 3};
    Point b = {2, 3};

    if (a == b) {
        cout << "Points a and b are equal (based on operator==)\n";
    }

    // ----- Check if point exists in set -----
    if (pointSet.find({2, 3}) != pointSet.end()) {
        cout << "(2, 3) is found in the set.\n";
    }

    return 0;
}
