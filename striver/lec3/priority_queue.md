# priority_queue in C++ STL

priority_queue is a max-heap by default, where the largest element is at the top.

## Key Features:
- Max-heap by default
- O(log n) insert and delete
- O(1) access to top

## Common Functions:
- push(value)
- pop()
- top()
- size()
- empty()

## Example: Finding Top K Largest Numbers

In data analysis, finding the top k largest values from a dataset is common.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    int k = 3;
    priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap for top k
    
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    cout << "Top " << k << " largest numbers: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
    // Output: Top 3 largest numbers: 5 6 9
    return 0;
}
```