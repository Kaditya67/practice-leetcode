#include <bits/stdc++.h>
using namespace std;

// Function to merge overlapping intervals
vector<pair<int, int>> mergeIntervals(vector<pair<int, int>>& intervals) {
    if (intervals.empty()) return {};

    // Sort by start time
    sort(intervals.begin(), intervals.end());

    vector<pair<int, int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < (int)intervals.size(); i++) {
        if (intervals[i].first <= merged.back().second) {
            // Overlap: merge by updating the end time
            merged.back().second = max(merged.back().second, intervals[i].second);
        } else {
            // No overlap: add new interval
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

int main() {
    // Sample input: overlapping intervals
    vector<pair<int, int>> intervals = {
        {1, 3}, {2, 6}, {8, 10}, {15, 18}
    };

    vector<pair<int, int>> result = mergeIntervals(intervals);

    cout << "Merged Intervals:\n";
    for (auto& interval : result) {
        cout << "[" << interval.first << ", " << interval.second << "]\n";
    }

    return 0;
}
