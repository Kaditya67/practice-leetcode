/**
 * PROBLEM: LeetCode 232 - Implement Queue using Stacks
 * CodeChef: ONP (Transform the Expression) - Stack Logic
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
  stack<int> st, tmpSt;
  MyQueue() {}

  void push(int x) { st.push(x); }

  int pop() {
    if (st.empty())
      return -1;
    while (!st.empty()) {
      tmpSt.push(st.top());
      st.pop();
    }
    int popped = tmpSt.top();
    tmpSt.pop();
    while (!tmpSt.empty()) {
      st.push(tmpSt.top());
      tmpSt.pop();
    }
    return popped;
  }

  int peek() {
    if (st.empty())
      return -1;
    while (!st.empty()) {
      tmpSt.push(st.top());
      st.pop();
    }
    int peek = tmpSt.top();
    while (!tmpSt.empty()) {
      st.push(tmpSt.top());
      tmpSt.pop();
    }
    return peek;
  }

  bool empty() { return st.empty(); }
};

int main() {
  MyQueue myQueue;
  myQueue.push(1);
  myQueue.push(2);
  cout << "Peek: " << myQueue.peek() << " (Expected: 1)" << endl;
  cout << "Pop: " << myQueue.pop() << " (Expected: 1)" << endl;
  cout << "Empty: " << boolalpha << myQueue.empty() << " (Expected: false)"
       << endl;

  return 0;
}
