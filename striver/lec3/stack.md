# stack in C++ STL

stack is a LIFO (Last In First Out) data structure.

## Key Features:
- LIFO
- O(1) push and pop

## Common Functions:
- push(value)
- pop()
- top()
- size()
- empty()

## Example: Checking Balanced Parentheses

A common problem in code editors is checking if parentheses are balanced in an expression.

```cpp
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string expr) {
    stack<char> s;
    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    string expr = "{[()]}";
    if (isBalanced(expr)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not balanced" << endl;
    }
    // Output: Balanced
    return 0;
}
```