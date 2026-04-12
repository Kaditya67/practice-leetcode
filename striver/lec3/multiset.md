# multiset in C++ STL

multiset is similar to set but allows duplicate elements. Elements are sorted.

## Key Features:
- Allows duplicates
- Elements are sorted
- O(log n) for operations

## Common Functions:
- insert(value)
- erase(value) or erase(iterator)
- find(value)
- count(value)
- size()
- empty()
- lower_bound(value)
- upper_bound(value)

## Example: Maintaining Sorted Exam Scores

Keeping track of exam scores in sorted order, allowing duplicates.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> scores;
    scores.insert(85);
    scores.insert(92);
    scores.insert(78);
    scores.insert(92); // duplicate score
    scores.insert(88);
    
    cout << "Sorted scores: ";
    for (int score : scores) {
        cout << score << " ";
    }
    cout << endl;
    
    // Find scores >= 90
    auto it = scores.lower_bound(90);
    cout << "Scores >= 90: ";
    for (; it != scores.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // Output:
    // Sorted scores: 78 85 88 92 92
    // Scores >= 90: 92 92
    return 0;
}
```