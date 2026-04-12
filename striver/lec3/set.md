# Set in C++ STL

Set is a container that stores unique elements in sorted order. It is implemented as a balanced binary search tree.

## Key Features:
- Stores unique elements
- Elements are sorted
- O(log n) time for insert, delete, search

## Common Functions:
- insert(value)
- erase(value)
- find(value)
- count(value)
- size()
- empty()
- lower_bound(value)
- upper_bound(value)

## Example: Removing Duplicates from User IDs

A common problem is processing a list of user IDs and removing duplicates while keeping them sorted.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> userIDs = {102, 101, 103, 101, 102, 104};
    set<int> uniqueIDs(userIDs.begin(), userIDs.end());
    
    cout << "Unique user IDs: ";
    for (int id : uniqueIDs) {
        cout << id << " ";
    }
    cout << endl;
    // Output: Unique user IDs: 101 102 103 104
    return 0;
}
```