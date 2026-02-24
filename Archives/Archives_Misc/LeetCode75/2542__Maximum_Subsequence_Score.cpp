// Problem: https://leetcode.com/problems/maximum-subsequence-score/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums1.size(); ++i) {
            pairs.push_back({nums1[i], nums2[i]});
        }

        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            return b.second < a.second;  // sort by nums2 descending
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0, res = 0;
        for (auto &[a, b] : pairs) {
            minHeap.push(a);
            sum += a;

            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == k) {
                res = max(res, sum * b);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {2, 1, 14, 7, 4};
    vector<int> nums2 = {3, 5, 10, 8, 5};
    int k = 2;
    cout << s.maxScore(nums1, nums2, k) << endl;
    return 0;
}
