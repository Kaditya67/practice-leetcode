#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit; // sort by profit descending
}

int jobScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), cmp);

    int maxDeadline = 0;
    for (auto &job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<int> slot(maxDeadline + 1, -1); // slot[i] = job id at time i
    int totalProfit = 0;

    for (auto &job : jobs) {
        // Try to place job at the latest possible slot before deadline
        for (int j = job.deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }

    return totalProfit;
}

int main() {
    // Sample Jobs: {id, deadline, profit}
    vector<Job> jobs = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };

    int maxProfit = jobScheduling(jobs);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
