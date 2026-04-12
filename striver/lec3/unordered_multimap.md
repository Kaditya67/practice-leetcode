# unordered_multimap in C++ STL

unordered_multimap allows multiple values for the same key, no order.

## Key Features:
- Allows multiple values per key
- No order
- Average O(1) access

## Common Functions:
- insert({key, value})
- erase(key) or erase(iterator)
- find(key)
- count(key)
- equal_range(key)

## Example: Phone Book with Multiple Numbers

Storing multiple phone numbers for each contact in a phone book.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_multimap<string, string> phoneBook;
    phoneBook.insert({"John", "123-456-7890"});
    phoneBook.insert({"John", "098-765-4321"});
    phoneBook.insert({"Jane", "555-123-4567"});
    
    string name = "John";
    cout << "Phone numbers for " << name << ":" << endl;
    auto range = phoneBook.equal_range(name);
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << endl;
    }
    // Output:
    // 123-456-7890
    // 098-765-4321
    return 0;
}
```