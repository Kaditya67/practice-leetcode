# unordered_set in C++ STL

unordered_set is a container that stores unique elements in no particular order. It uses hashing for fast lookups.

## Key Features:
- Stores unique elements
- Average O(1) time for insert, delete, search
- Implemented as hash table

## Common Functions:
- insert(value)
- erase(value)
- find(value)
- count(value)
- size()
- empty()

## Example: Checking for Duplicate Emails

In a real-world application, you might need to check if there are duplicate emails in a list for validation.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> emails = {"user1@example.com", "user2@example.com", "user1@example.com", "user3@example.com"};
    unordered_set<string> uniqueEmails;
    bool hasDuplicates = false;
    
    for (string email : emails) {
        if (uniqueEmails.find(email) != uniqueEmails.end()) {
            hasDuplicates = true;
            break;
        }
        uniqueEmails.insert(email);
    }
    
    if (hasDuplicates) {
        cout << "Duplicate emails found!" << endl;
    } else {
        cout << "All emails are unique." << endl;
    }
    // Output: Duplicate emails found!
    return 0;
}
```