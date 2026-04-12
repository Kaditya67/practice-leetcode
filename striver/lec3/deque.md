# deque in C++ STL

deque (double-ended queue) allows insertion and deletion from both ends.

## Key Features:
- Insertion/deletion from both ends
- Random access
- O(1) for push/pop front/back

## Common Functions:
- push_front(value)
- push_back(value)
- pop_front()
- pop_back()
- front()
- back()
- at(index) or []
- size()
- empty()

## Example: Sliding Window Maximum

Finding the maximum in each window of size k in an array, useful in signal processing or stock price analysis.

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq; // stores indices
    
    for (int i = 0; i < nums.size(); i++) {
        // remove elements out of window
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        // remove smaller elements
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        // add to result when window is complete
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> maxes = maxSlidingWindow(nums, k);
    cout << "Sliding window maximums: ";
    for (int m : maxes) cout << m << " ";
    cout << endl;
    // Output: Sliding window maximums: 3 3 5 5 6 7
    return 0;
}
```