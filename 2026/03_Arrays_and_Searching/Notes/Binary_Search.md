# Concept Name: Binary Search (Classic vs. On Answer)

## 1. Intuition and Core Logic
- **Use Case**: Searching in a sorted space (or a space with a monotonic property) to reduce $O(N)$ searches to $O(\log N)$.
- **Problem Type**: Finding an element in a sorted array, finding the first/last occurrence, or searching for the "maximum possible minimum value".

---

## 2. Classic Binary Search (Three Patterns)

### Pattern 1: Find Exact Value
```cpp
int low = 0, high = n - 1;
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (A[mid] == target) return mid;
    if (A[mid] < target) low = mid + 1;
    else high = mid - 1;
}
```

### Pattern 2: Find First/Last (Lower/Upper Bound)
- **Logic**: Use `low < high` and careful updating to find the boundary of a condition.

---

## 3. Binary Search on Answer (The "Hard" Pattern)
- **Condition**: If a value $X$ is possible, then all values $< X$ are also possible. This is a **Monotonic Function**.
- **Logic**:
    1.  Define the range $[L, R]$ (the answer must be in this range).
    2.  Check the middle value `mid`.
    3.  If `check(mid)` is true, move toward the better answer. If false, shrink the range.

```cpp
long long low = 0, high = 1e12, ans = 0;
while (low <= high) {
    long long mid = low + (high - low) / 2;
    if (can_do(mid)) {
        ans = mid;
        low = mid + 1; // Try for a larger answer
    } else {
        high = mid - 1;
    }
}
```

---

## 4. Decision Matrix (Read This First)
1. **Sorted array?** -> Classic Binary Search.
2. **Problem asks for "Minimum of maximum" or "Maximum of minimum"?** -> Binary Search on Answer.
3. **Sorted duplicates?** -> Use `std::lower_bound` or `std::upper_bound` logic.
4. **Range is very large ($10^{18}$)?** -> Always use Binary Search on Answer.
