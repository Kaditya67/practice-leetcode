#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid) {
    int cowCount = 1;
    int lastPosition = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPosition >= mid) {
            cowCount++;
            if (cowCount == k) {
                return true;
            }
            lastPosition = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int start = 1;
    int end = stalls[stalls.size() - 1] - stalls[0];
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossible(stalls, k, mid)) {
            ans = mid;
            start = mid + 1; // check for a larger distance
        } else {
            end = mid - 1; // check for a possible answer in the smaller range
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    cout << "The largest minimum distance is: " << aggressiveCows(stalls, k) << endl;
    return 0;
}
