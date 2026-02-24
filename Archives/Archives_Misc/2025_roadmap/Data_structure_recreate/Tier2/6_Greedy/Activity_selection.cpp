#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

// Comparator to sort activities by finish time
bool cmp(Activity a, Activity b) {
    return a.finish < b.finish;
}

// Greedy function to find the maximum number of non-overlapping activities
int maxActivities(vector<Activity> &activities) {
    sort(activities.begin(), activities.end(), cmp);

    int count = 1;  // first activity is always selected
    int lastFinish = activities[0].finish;

    for (int i = 1; i < (int)activities.size(); i++) {
        if (activities[i].start >= lastFinish) {
            count++;
            lastFinish = activities[i].finish;
        }
    }
    return count;
}

int main() {
    // Sample input: start and finish times of activities
    vector<Activity> activities = {
        {1, 3},
        {2, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };

    cout << "Maximum number of non-overlapping activities: "
         << maxActivities(activities) << endl;

    return 0;
}
