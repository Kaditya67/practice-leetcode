# Concept Name: Parsing and Simulation (Parentheses, Queues)

## 1. Intuition and Core Logic
- **Use Case**: Processing nested structures (LIFO) or sequential events (FIFO).
- **Problem Type**: Valid Parentheses, Simplifying Paths, or Sliding Window Maximum (using Deque).

---

## 2. Parentheses and Expression Parsing
- **Logic**: Use a stack to track open brackets. When a closing bracket appears, it must match the top of the stack.
- **Extension**: For more complex expressions (e.g., "3[a]2[bc]"), use stacks to store counts and partial strings.

---

## 3. Queue and Deque Patterns

### Sequential Simulation (Queue)
- **Logic**: Process elements in the order they arrive. Used for BFS (Breadth-First Search) and task scheduling.

### Sliding Window Maximum (Deque)
- **Logic**: Use a `std::deque` to maintain indices of elements in the current window in a monotonic order (decreasing). This allows $O(1)$ access to the window's maximum.

---

## 4. Stack Simulation of Recursion
- **Logic**: Any recursive function can be turned into an iterative one using a manual stack. This is useful for avoiding stack overflow and understanding the recursion's "state".

---

## 5. Decision Matrix (Read This First)
1. **Nested structure or "undo" logic?** -> Use a Stack.
2. **"First in, first out" or "Wait in line"?** -> Use a Queue.
3. **Need to access/remove from both ends?** -> Use a Deque.
4. **Validating brackets/delimiters?** -> Use a Stack.
5. **Level-order processing?** -> Use a Queue (BFS).
