# Concept Name: Sorting Techniques (Stable Sort, Custom Ties)

## 1. Intuition and Core Logic
- **Use Case**: Organizing data to enable $O(N)$ or $O(\log N)$ processing. Sorting is the most common "Preprocessing Transform" in competitive programming.
- **Problem Type**: Simplifying logic by ensuring elements are processed in a specific order (e.g., ascending, descending, or by custom priority).

---

## 2. Custom Comparators and Tie-Breakers
- **Standard Sort**: `std::sort` uses `operator<`.
- **Custom Sort**: You can provide a custom function/lambda to define priority.
- **Tie-Breakers**: When two elements have the same primary key, a secondary key must decide the order to ensure stability and predictability.

```cpp
struct Node {
    int val, pos;
};

// Sort by value ascending, then by position descending if values are equal.
sort(nodes.begin(), nodes.end(), [](const Node& a, const Node& b) {
    if (a.val != b.val) return a.val < b.val;
    return a.pos > b.pos; 
});
```

---

## 3. Stable vs. Unstable Sort
- **Unstable (`std::sort`)**: Does not guarantee the relative order of equal elements. Performance is $O(N \log N)$.
- **Stable (`std::stable_sort`)**: Maintains relative order of equal elements. Useful when multiple sorting passes are needed.

---

## 4. Sorting as a Transform
- **Example**: If asked to find if any two numbers in an array are equal, brute force is $O(N^2)$. After sorting ($O(N \log N)$), you only need to check adjacent elements ($O(N)$).

---

## 5. Decision Matrix (Read This First)
1. **Need to process elements in order?** -> Sort first.
2. **Multiple sorting criteria?** -> Use a custom comparator with clear tie-breakers.
3. **Relative order of equal elements matters?** -> Use `std::stable_sort`.
4. **Need to find the $K$-th smallest element?** -> Consider `std::nth_element` for $O(N)$ average time.
