# map in C++ STL

map is a container that stores key-value pairs with unique keys in sorted order.

## Key Features:
- Unique keys
- Keys are sorted
- O(log n) access

## Common Functions:
- insert({key, value}) or [key] = value
- erase(key)
- find(key)
- count(key)
- size()
- empty()
- at(key) or []
- lower_bound(key)
- upper_bound(key)

## Example: Word Frequency Counter

A common real-world problem is counting the frequency of words in a text. Map can be used to store words as keys and their counts as values, keeping them sorted.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string text = "apple banana apple orange banana apple";
    map<string, int> wordCount;
    
    stringstream ss(text);
    string word;
    while (ss >> word) {
        wordCount[word]++;
    }
    
    cout << "Word frequencies:" << endl;
    for (auto &p : wordCount) {
        cout << p.first << ": " << p.second << endl;
    }
    // Output:
    // apple: 3
    // banana: 2
    // orange: 1
    return 0;
}
```