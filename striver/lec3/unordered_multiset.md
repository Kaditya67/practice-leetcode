# unordered_multiset in C++ STL

unordered_multiset is similar to unordered_set but allows duplicate elements. It uses hashing.

## Key Features:
- Allows duplicates
- No particular order
- Average O(1) for operations

## Common Functions:
- insert(value)
- erase(value) or erase(iterator)
- find(value)
- count(value)
- size()
- empty()

## Example: Vote Counting with Multiple Votes

In a voting system where voters can vote multiple times for different candidates.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_multiset<string> votes;
    votes.insert("Alice");
    votes.insert("Bob");
    votes.insert("Alice");
    votes.insert("Charlie");
    votes.insert("Alice");
    
    cout << "Vote counts:" << endl;
    cout << "Alice: " << votes.count("Alice") << endl;
    cout << "Bob: " << votes.count("Bob") << endl;
    cout << "Charlie: " << votes.count("Charlie") << endl;
    // Output:
    // Alice: 3
    // Bob: 1
    // Charlie: 1
    return 0;
}
```