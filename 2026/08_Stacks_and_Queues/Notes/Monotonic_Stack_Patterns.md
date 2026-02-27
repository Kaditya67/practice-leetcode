# Concept Name: Monotonic Stack Patterns (Next Greater Element)

## 1. Intuition and Core Logic
- **Use Case**: Finding the first element to the left or right that is larger or smaller than the current element.
- **Problem Type**: Next Greater Element, Daily Temperatures, or Largest Rectangle in Histogram.
- **The Core Pattern**: Maintain a stack where elements are kept in a strictly increasing or decreasing order. When a new element violates this order, pop elements until the order is restored.

---

## 2. Next Greater Element Pattern
To find the next greater element for each index:
1.  Iterate through the array.
2.  While the stack is not empty and the current element is greater than the stack's top, the current element is the "Next Greater" for that top element.
3.  Pop the top and repeat.
4.  Push the current element onto the stack.

```cpp
vector<int> nge(n, -1);
stack<int> st;
for (int i = 0; i < n; i++) {
    while (!st.empty() && A[i] > A[st.top()]) {
        nge[st.top()] = A[i];
        st.pop();
    }
    st.push(i);
}
```

---

## 3. Complexity Analysis
- **Time**: $O(N)$. Each element is pushed onto the stack exactly once and popped at most once.
- **Space**: $O(N)$ for the stack.

---

## 4. Decision Matrix (Read This First)
1. **Need the "nearest" greater/smaller element?** -> Use a Monotonic Stack.
2. **Problem involves a "look back" or "look ahead" for extrema?** -> Think of Monotonic Stack.
3. **Circular array?** -> Run the loop twice (0 to $2N-1$) with `i % n`.
4. **Need both left and right boundaries?** -> Run the monotonic stack twice or handle both inside one loop.
