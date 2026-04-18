# next_permutation in STL

next_permutation generates the next lexicographical permutation of the sequence.

## Usage:
- #include `<algorithm>`
- bool next_permutation(begin, end)

Returns true if there is a next permutation, false otherwise.

## Example: Generating All Permutations of a Word

In word games or cryptography, generating all possible arrangements of letters in a word.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string word = "abc";
    sort(word.begin(), word.end()); // important for next_permutation
    cout << "All permutations of '" << word << "':" << endl;
    do {
        cout << word << endl;
    } while (next_permutation(word.begin(), word.end()));
    // Output:
    // abc
    // acb
    // bac
    // 
    // cab
    // cba
    return 0;
}
```