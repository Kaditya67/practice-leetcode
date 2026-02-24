# COMPLEXITY CHEAT SHEET: Quick Reference

Never guess if your solution is fast enough. Use the input constraint ($N$) to determine the exact Time Complexity expected by the platform.

---

## ⏱️ Constraint-to-Complexity Decoder
Given $N$ (the max size of input array/string/nodes):

| Constraint ($N$) | Allowed Complexity | Expected Algorithm Type |
| :--- | :--- | :--- |
| $N \le 10..12$ | $O(N!)$ or $O(N \cdot 2^N)$ | Backtracking, Permutations, TSP (Bitmask DP) |
| $N \le 15..20$ | $O(2^N)$ | Subset generation, Meet in the Middle |
| $N \le 100$ | $O(N^4)$ or $O(N^3)$ | Floyd-Warshall, 3D DP, Matrix Exponentiation |
| $N \le 1,000$ | $O(N^2)$ | Simple DP, Insertion/Selection Sort, Nested Loops |
| $N \le 10^5$ | $O(N \log N)$ | Sorting, Binary Search, Heaps, Sweepline |
| $N \le 10^6$ | $O(N)$ | Two Pointers, Sliding Window, Linear DP, Greedy |
| $N \ge 10^9$ | $O(\log N)$ or $O(1)$ | Binary Search on Answer, Math formulas |

*(Note: Most online judges restrict operations to $\approx 10^8$ operations per second.)*

---

## 🛠️ Average C++ STL Complexities

### Vector (`std::vector`)
- Push back: $O(1)$ amortized.
- Insert/Delete at specific index: $O(N)$.
- Access: $O(1)$.

### Hash Map/Set (`std::unordered_map` / `std::unordered_set`)
- Insert/Delete/Lookup: $O(1)$ on average.
- Worst case: $O(N)$ (if hash collisions occur, extremely rare).

### Ordered Map/Set (`std::map` / `std::set` - Red Black Trees)
- Insert/Delete/Lookup: $O(\log N)$.
- Contains data in sorted order.

### Priority Queue (`std::priority_queue` - Heap)
- Push (insert): $O(\log N)$.
- Pop (extract min/max): $O(\log N)$.
- Top (peek): $O(1)$.
- Heapify (Building a heap from an array): $O(N)$.
