# sort() in C++ STL

sort() sorts the elements in the range [first, last) in ascending order.

## Usage:
- #include <algorithm>
- sort(begin, end)
- sort(begin, end, comparator)

## Time Complexity:
- O(n log n)

## Example: Sorting Students by Marks

In an educational system, sorting students based on their marks for ranking.

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int marks;
};

bool compareByMarks(const Student &a, const Student &b) {
    return a.marks > b.marks; // descending order
}

int main() {
    vector<Student> students = {
        {"Alice", 85},
        {"Bob", 92},
        {"Charlie", 78},
        {"David", 95}
    };
    
    sort(students.begin(), students.end(), compareByMarks);
    
    cout << "Students sorted by marks (descending):" << endl;
    for (auto &s : students) {
        cout << s.name << ": " << s.marks << endl;
    }
    // Output:
    // David: 95
    // Bob: 92
    // Alice: 85
    // Charlie: 78
    return 0;
}
```