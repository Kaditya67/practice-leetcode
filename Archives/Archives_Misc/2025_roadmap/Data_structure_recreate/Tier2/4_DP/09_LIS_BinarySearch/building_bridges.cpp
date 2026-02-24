#include <bits/stdc++.h>
using namespace std;

int maxBridges(vector<pair<int, int>>& bridges) {
    // Step 1: Sort by north bank
    sort(bridges.begin(), bridges.end());

    // Step 2: Extract south bank sequence
    vector<int> south;
    for (auto& bridge : bridges)
        south.push_back(bridge.second);

    // Step 3: Apply LIS on south bank
    vector<int> lis;
    for (int s : south) {
        auto it = lower_bound(lis.begin(), lis.end(), s);
        if (it == lis.end())
            lis.push_back(s);
        else
            *it = s;
    }

    return lis.size();
}

int main() {
    vector<pair<int, int>> bridges = {
        {6, 2}, {4, 3}, {2, 6}, {1, 5}, {3, 4}, {5, 1}
    };

    cout << "Max number of bridges: " << maxBridges(bridges) << endl;
    return 0;
}
