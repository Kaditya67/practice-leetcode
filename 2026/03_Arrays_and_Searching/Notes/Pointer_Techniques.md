# Concept Name: Pointer Techniques (Two Pointers, Sliding Window)

## 1. Intuition and Core Logic
- **Use Case**: Processing arrays or strings in a single pass ($O(N)$) by narrowing the search space or maintaining a valid window.
- **Problem Type**: Finding pairs with a sum, reversing arrays, or finding the longest/shortest substring with a property.

---

## 2. Two Pointers

### Meet-in-the-Middle Pattern
- **Logic**: Start pointers at `left = 0` and `right = N-1`. Move them toward each other based on a condition (e.g., target sum in a sorted array).
- **Complexity**: $O(N)$ (assuming sorted).

### Fast and Slow Pointers
- **Logic**: One pointer moves faster than the other (e.g., finding the middle of a linked list or cycle detection).

---

## 3. Sliding Window

### Fixed-Size Window
- **Logic**: Maintain a window of size $K$. Slide it by adding the next element and removing the leftmost element.
- **Complexity**: $O(N)$.

### Variable-Size Window (Expand/Shrink)
- **Logic**: Expand the `right` pointer to include elements. If the window becomes invalid, shrink the `left` pointer until it's valid again.
- **Complexity**: $O(N)$ (each pointer moves at most $N$ times).

```cpp
int left = 0, right = 0;
while (right < N) {
    add(A[right]);
    while (is_invalid()) {
        remove(A[left]);
        left++;
    }
    update_result();
    right++;
}
```

---

## 4. Decision Matrix (Read This First)
1. **Array is sorted?** -> Think Two Pointers.
2. **Problem mentions "contiguous subarray" or "substring"?** -> Think Sliding Window.
3. **Need to find a sub-structure of size $K$?** -> Fixed Sliding Window.
4. **Need to find the longest/shortest sub-structure with property $X$?** -> Variable Sliding Window.
