// Problem: https://leetcode.com/problems/total-cost-to-hire-k-workers/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int left = 0, right = n - 1;
        long long total = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> leftHeap, rightHeap;

        while (leftHeap.size() < candidates && left <= right) {
            leftHeap.push({costs[left], left}); // Cost, Index
            ++left;
        }

        while (rightHeap.size() < candidates && left <= right) {
            rightHeap.push({costs[right], right});
            --right;
        }

        for (int i = 0; i < k; ++i) {
            if (!leftHeap.empty() && (rightHeap.empty() || leftHeap.top() <= rightHeap.top())) {
                auto [cost, idx] = leftHeap.top(); leftHeap.pop();
                total += cost;

                if (left <= right) {
                    leftHeap.push({costs[left], left});
                    ++left;
                }
            }else {
                auto [cost, idx] = rightHeap.top(); rightHeap.pop();
                total += cost;

                if (left <= right) {
                    rightHeap.push({costs[right], right});
                    --right;
                }
            }
            
        }

        return total;
    }
};


// No index storing
class Solution2 {
 public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    long ans = 0;
    int i = 0;
    int j = costs.size() - 1;
    priority_queue<int, vector<int>, greater<>> minHeapL;
    priority_queue<int, vector<int>, greater<>> minHeapR;

    for (int hired = 0; hired < k; ++hired) {
      while (minHeapL.size() < candidates && i <= j)
        minHeapL.push(costs[i++]);      // Adding from smallest to largest
      while (minHeapR.size() < candidates && i <= j)
        minHeapR.push(costs[j--]);      // Adding from largest to smallest
      if (minHeapL.empty())
        ans += minHeapR.top(), minHeapR.pop();
      else if (minHeapR.empty())
        ans += minHeapL.top(), minHeapL.pop();
      else if (minHeapL.top() <= minHeapR.top())
        ans += minHeapL.top(), minHeapL.pop();      // If both are the same, choose the smallest from minHeapL
      else
        ans += minHeapR.top(), minHeapR.pop();
    }

    return ans;
  }
};

int main() {
    Solution s;
    vector<int> costs = {17,12,10,2,7,2,11,20,8,6,2,11,16,1,4,11,12,5,2,15,6,14,9,1,3,4};
    int k = 3;
    cout << s.totalCost(costs, k) << endl; // 11
    return 0;
}
