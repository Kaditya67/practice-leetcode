# list in C++ STL

list is a doubly-linked list.

## Key Features:
- Doubly-linked
- O(1) insert/delete at any position if iterator is known
- No random access

## Common Functions:
- push_front(value)
- push_back(value)
- pop_front()
- pop_back()
- insert(iterator, value)
- erase(iterator)
- size()
- empty()

## Example:
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(0);
    for(int x : l) cout << x << " "; // 0 1 2
    cout << endl;
    return 0;
}
```