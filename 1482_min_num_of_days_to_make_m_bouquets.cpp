#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool checkBq(vector<int>& bloomDay, int m, int k, int day) {
        int bq = 0;
        int count = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                count++;
            } else {
                count = 0;
            }
            if (count == k) {
                bq++;
                count = 0; // reset count after making a bouquet
            }

            if (bq >= m) {
                return true;
            }
        }

        return false;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m * k > n) return -1; // Not enough flowers

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (checkBq(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main() {
    Solution sol;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    int result = sol.minDays(bloomDay, m, k);
    cout << "Minimum days to make " << m << " bouquets: " << result << endl;

    return 0;
}
