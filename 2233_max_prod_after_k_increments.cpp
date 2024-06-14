#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        // Use a min-heap to always increment the smallest element
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());

        // Perform k increments
        while (k > 0) {
            int smallest = minHeap.top();
            minHeap.pop();
            smallest++;
            minHeap.push(smallest);
            k--;
        }

        // Calculate the product of elements
        long long prod = 1;
        int MOD = 1e9 + 7;
        while (!minHeap.empty()) {
            prod = (prod * minHeap.top()) % MOD;
            minHeap.pop();
        }

        return (int)prod;
    }
};

// Example usage
int main() {
    Solution s;
    vector<int> nums = {9, 7, 8};
    int k = 9;

    cout << s.maximumProduct(nums, k) << endl; // Expected output: 1331
    return 0;
}
