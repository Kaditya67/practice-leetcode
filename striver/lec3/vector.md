# Vector in C++ STL

Vector is a dynamic array that can resize itself automatically when elements are inserted or deleted.

## Key Features:
- Dynamic size
- Random access in O(1)
- Amortized O(1) for push_back

## Common Functions:
- push_back(value)
- pop_back()
- size()
- empty()
- at(index) or []
- insert(position, value)
- erase(position)

## Example: Finding Maximum Sales Day

In a real-world scenario, you might have daily sales data stored in a vector and need to find the day with maximum sales.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> sales = {100, 200, 150, 300, 250}; // sales per day
    int maxSales = 0;
    int maxDay = -1;
    
    for (int i = 0; i < sales.size(); i++) {
        if (sales[i] > maxSales) {
            maxSales = sales[i];
            maxDay = i + 1; // days start from 1
        }
    }
    
    cout << "Maximum sales: " << maxSales << " on day " << maxDay << endl;
    // Output: Maximum sales: 300 on day 4
    return 0;
}
```