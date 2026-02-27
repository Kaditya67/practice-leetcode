/**
 * PROBLEM: LeetCode 232 - Implement Queue using Stacks
 * ORDER: 07
 * ATOMIC TOPIC: Container Simulation
 * 
 * DESCRIPTION:
 * Implement a first in first out (FIFO) queue using only two stacks. 
 * The implemented queue should support push, pop, peek, and empty.
 * 
 * CONSTRAINTS:
 * - 1 <= x <= 9
 * - At most 100 calls will be made to push, pop, peek, and empty.
 */

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {}
    
    void push(int x) {
        // TODO: Implement push
    }
    
    int pop() {
        // TODO: Implement pop
        return 0;
    }
    
    int peek() {
        // TODO: Implement peek
        return 0;
    }
    
    bool empty() {
        // TODO: Implement empty
        return true;
    }
};

int main() {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    cout << "Peek: " << myQueue.peek() << " (Expected: 1)" << endl;
    cout << "Pop: " << myQueue.pop() << " (Expected: 1)" << endl;
    cout << "Empty: " << boolalpha << myQueue.empty() << " (Expected: false)" << endl;

    return 0;
}
