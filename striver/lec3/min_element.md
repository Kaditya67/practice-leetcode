# min_element() in C++ STL

min_element() returns an iterator to the smallest element in the range.

## Usage:
- #include <algorithm>
- min_element(begin, end)

## Example: Finding Minimum Temperature

In weather data analysis, finding the coldest day in a week.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> temperatures = {25, 22, 28, 20, 26, 24, 23}; // temperatures in Celsius
    auto minTemp = min_element(temperatures.begin(), temperatures.end());
    int day = minTemp - temperatures.begin() + 1; // day number
    
    cout << "Minimum temperature: " << *minTemp << "°C on day " << day << endl;
    // Output: Minimum temperature: 20°C on day 4
    return 0;
}
```