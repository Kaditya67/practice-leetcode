#include <bits/stdc++.h>
using namespace std;

int maxEnvelopes(vector<vector<int>>& envelopes) {
    // Sort by width ↑ and height ↓
    sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });

    // Extract heights only
    vector<int> heights;
    for (auto& env : envelopes)
        heights.push_back(env[1]);

    // LIS on heights
    vector<int> lis;
    for (int h : heights) {
        auto it = lower_bound(lis.begin(), lis.end(), h);
        if (it == lis.end()) lis.push_back(h);
        else *it = h;
    }

    return lis.size();
}

int main() {
    vector<vector<int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
    cout << "Max envelopes nested: " << maxEnvelopes(envelopes) << endl;
    return 0;
}
