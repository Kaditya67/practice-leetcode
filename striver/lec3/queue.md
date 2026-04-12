# queue in C++ STL

queue is a FIFO (First In First Out) data structure.

## Key Features:
- FIFO
- O(1) push and pop

## Common Functions:
- push(value)
- pop()
- front()
- back()
- size()
- empty()

## Example: Bank Queue Simulation

Simulating customers waiting in a bank queue, serving them in order.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<string> bankQueue;
    bankQueue.push("Customer A");
    bankQueue.push("Customer B");
    bankQueue.push("Customer C");
    
    cout << "Serving customers:" << endl;
    while (!bankQueue.empty()) {
        cout << "Now serving: " << bankQueue.front() << endl;
        bankQueue.pop();
    }
    // Output:
    // Now serving: Customer A
    // Now serving: Customer B
    // Now serving: Customer C
    return 0;
}
```