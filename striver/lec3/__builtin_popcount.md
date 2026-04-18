# `__builtin_popcount()` in C++

`__builtin_popcount()` counts how many set bits are present in a number.

Set bit means a bit whose value is `1`.

Example:
- `5` in binary is `101`, so set bits = `2`
- `7` in binary is `111`, so set bits = `3`
- `8` in binary is `1000`, so set bits = `1`

This is also called:
- number of `1`s in binary representation
- bit count
- population count
- Hamming weight

## Why it is useful

In bit manipulation problems, we often need answers like:
- How many features are turned on?
- Is the count of `1`s even or odd?
- Is a number a power of 2?
- Among many masks, which one has more selected elements?

Instead of writing a loop over all bits every time, `__builtin_popcount()` gives the count directly.

## Syntax

```cpp
__builtin_popcount(x);    // for int
__builtin_popcountl(x);   // for long
__builtin_popcountll(x);  // for long long
```

## Important point

Use the correct version based on the type:
- `int` -> `__builtin_popcount`
- `long long` -> `__builtin_popcountll`

If your number is `long long`, prefer `__builtin_popcountll()` to avoid mistakes.

## Small examples

| Number | Binary | Set bits |
|--------|--------|----------|
| 0 | 0000 | 0 |
| 1 | 0001 | 1 |
| 2 | 0010 | 1 |
| 3 | 0011 | 2 |
| 5 | 0101 | 2 |
| 7 | 0111 | 3 |
| 8 | 1000 | 1 |

## Basic Example

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 13; // binary = 1101
    cout << __builtin_popcount(x) << endl;
    return 0;
}
```

Output:

```cpp
3
```

Because `13 = 1101`, and there are `3` ones.

## Example: Counting set bits for many numbers

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};

    for (int num : numbers) {
        cout << num << " -> "
             << bitset<4>(num) << " -> "
             << __builtin_popcount(num) << " set bits\n";
    }

    return 0;
}
```

Output:

```cpp
1 -> 0001 -> 1 set bits
2 -> 0010 -> 1 set bits
3 -> 0011 -> 2 set bits
4 -> 0100 -> 1 set bits
5 -> 0101 -> 2 set bits
6 -> 0110 -> 2 set bits
7 -> 0111 -> 3 set bits
8 -> 1000 -> 1 set bits
```

## Example: Odd parity / even parity

Parity means whether the number of set bits is odd or even.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};

    cout << "Numbers with odd parity:\n";

    for (int num : numbers) {
        int bits = __builtin_popcount(num);
        if (bits % 2 == 1) {
            cout << num << " (binary: " << bitset<4>(num)
                 << ", bits: " << bits << ")\n";
        }
    }

    return 0;
}
```

## Common interview / coding uses

### 1. Check if a number is a power of 2

A power of 2 has exactly one set bit.

Examples:
- `1 = 0001`
- `2 = 0010`
- `4 = 0100`
- `8 = 1000`

```cpp
bool isPowerOfTwo(int n) {
    return n > 0 && __builtin_popcount(n) == 1;
}
```

### 2. Count selected elements in a bitmask

In bitmask problems, each bit often represents whether an element is chosen or not.

```cpp
int mask = 13; // binary = 1101
cout << __builtin_popcount(mask) << endl; // 3 elements selected
```

### 3. Sort numbers by number of set bits

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {5, 3, 7, 8};

    sort(v.begin(), v.end(), [](int a, int b) {
        return __builtin_popcount(a) < __builtin_popcount(b);
    });

    for (int x : v) cout << x << " ";
}
```

## With `long long`

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x = 1000000000000LL;
    cout << __builtin_popcountll(x) << endl;
    return 0;
}
```

## Time complexity

In coding interviews and competitive programming, treat it as very fast and effectively constant time for normal integer sizes.

## Common mistake

```cpp
long long x = 1e18;
cout << __builtin_popcount(x);   // avoid this
```

Better:

```cpp
long long x = 1e18;
cout << __builtin_popcountll(x); // correct
```

## Manual way vs builtin

Without builtin, we may write:

```cpp
int countBits(int n) {
    int cnt = 0;
    while (n > 0) {
        cnt += (n & 1);
        n = n >> 1;
    }
    return cnt;
}
```

This works, but `__builtin_popcount()` is shorter and cleaner.

## One more efficient manual trick

This removes the last set bit in each step:

```cpp
int countBits(int n) {
    int cnt = 0;
    while (n) {
        n = n & (n - 1);
        cnt++;
    }
    return cnt;
}
```

Why it works:
- `n & (n - 1)` removes the rightmost set bit
- so the loop runs only as many times as there are `1`s

Example for `n = 12`:
- `12 = 1100`
- `11 = 1011`
- `12 & 11 = 1000`

One set bit is removed.

## Summary

- `__builtin_popcount(x)` counts set bits in an `int`
- `__builtin_popcountll(x)` counts set bits in a `long long`
- very useful in bit manipulation and bitmask problems
- if set bits count is `1`, the number is a power of `2`
- parity can be checked using `__builtin_popcount(x) % 2`

## Practice thinking

Try these mentally:
- `10` -> binary `1010` -> answer `2`
- `15` -> binary `1111` -> answer `4`
- `16` -> binary `10000` -> answer `1`
- `31` -> binary `11111` -> answer `5`
