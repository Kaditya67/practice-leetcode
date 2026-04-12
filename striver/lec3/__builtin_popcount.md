# __builtin_popcount() in STL

__builtin_popcount() is a GCC builtin function that counts the number of set bits (1s) in an integer.

## Usage:
- For int: __builtin_popcount(x)
- For long long: __builtin_popcountll(x)

## Example: Counting Set Bits for Parity Check

In data transmission, checking if a number has even or odd parity (even/odd number of 1s).

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8}; // 1=1, 2=10, 3=11, 4=100, 5=101, 6=110, 7=111, 8=1000
    cout << "Numbers with odd parity (odd number of 1s):" << endl;
    for (int num : numbers) {
        int bits = __builtin_popcount(num);
        if (bits % 2 == 1) {
            cout << num << " (binary: " << bitset<4>(num) << ", bits: " << bits << ")" << endl;
        }
    }
    // Output:
    // 1 (binary: 0001, bits: 1)
    // 2 (binary: 0010, bits: 1)
    // 4 (binary: 0100, bits: 1)
    // 7 (binary: 0111, bits: 3)
    return 0;
}
```