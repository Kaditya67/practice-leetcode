# unordered_map in C++ STL

unordered_map is a container that stores key-value pairs with unique keys. Uses hashing for fast access.

## Key Features:
- Unique keys
- Average O(1) access
- No order

## Common Functions:
- insert({key, value}) or [key] = value
- erase(key)
- find(key)
- count(key)
- size()
- empty()
- at(key) or []

## Example: Character Frequency in a String

A practical problem is analyzing the frequency of characters in a text for compression or analysis.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string text = "hello world";
    unordered_map<char, int> charCount;
    
    for (char c : text) {
        if (c != ' ') { // ignore spaces
            charCount[c]++;
        }
    }
    
    cout << "Character frequencies:" << endl;
    for (auto &p : charCount) {
        cout << p.first << ": " << p.second << endl;
    }
    // Output:
    // h: 1
    // e: 1
    // l: 3
    // o: 2
    // w: 1
    // r: 1
    // d: 1
    return 0;
}
```