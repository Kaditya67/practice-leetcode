# max_element() in C++ STL

max_element() returns an iterator to the largest element in the range.

## Usage:
- #include <algorithm>
- max_element(begin, end)

## Example: Finding Highest Exam Score

In grading systems, finding the highest score among students.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> scores = {85, 92, 78, 95, 88, 90};
    auto maxScore = max_element(scores.begin(), scores.end());
    int studentIndex = maxScore - scores.begin() + 1; // student number
    
    cout << "Highest score: " << *maxScore << " by student " << studentIndex << endl;
    // Output: Highest score: 95 by student 4
    return 0;
}
```