# multimap in C++ STL

multimap allows multiple values for the same key, keys are sorted.

## Key Features:
- Multiple values per key
- Keys sorted
- O(log n) operations

## Common Functions:
- insert({key, value})
- erase(key) or erase(iterator)
- find(key)
- count(key)
- lower_bound(key)
- upper_bound(key)
- equal_range(key)

## Example: Event Calendar

Scheduling multiple events per date in a calendar application.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<string, string> calendar;
    calendar.insert({"2024-04-15", "Meeting with team"});
    calendar.insert({"2024-04-15", "Lunch with client"});
    calendar.insert({"2024-04-16", "Project deadline"});
    
    string date = "2024-04-15";
    cout << "Events on " << date << ":" << endl;
    auto range = calendar.equal_range(date);
    for (auto it = range.first; it != range.second; ++it) {
        cout << "- " << it->second << endl;
    }
    // Output:
    // Events on 2024-04-15:
    // - Meeting with team
    // - Lunch with client
    return 0;
}
```