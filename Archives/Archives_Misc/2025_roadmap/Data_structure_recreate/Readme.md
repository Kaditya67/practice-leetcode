# 📘 Time Complexity Patterns Cheat Sheet

## Core Recursion and DP Patterns

| Pattern / Recurrence               | Time Complexity | Why It Matters                      |
| ---------------------------------- | --------------- | ----------------------------------- |
| `fib(n)` naive recursion           | O(2^n)          | Classic exponential recursion       |
| `T(n) = T(n - 1) + O(1)`           | O(n)            | Linear recursion/tail recursion     |
| `T(n) = T(n - 1) + n`              | O(n^2)          | Arithmetic sum, nested loop analogy |
| `T(n) = 2T(n/2) + n`               | O(n log n)      | Merge sort recurrence               |
| `T(n) = T(n/2) + O(1)`             | O(log n)        | Binary search                       |
| Bottom-up DP (1D table)            | O(n)            | Fibonacci with tabulation           |
| 2D DP (Nested loops)               | O(n^2)          | Grid problems like Edit Distance    |
| 3D DP                              | O(n^3)          | Advanced DP like palindromes        |
| Matrix Exponentiation (Fibonacci)  | O(log n)        | Linear recurrence optimization      |
| `T(n) = T(n - 1) + T(n - 2)` (DP)  | O(n)            | DP memoization                      |
| `T(n) = T(n - k) + O(1)`           | O(n)            | Coin change with fixed-size steps   |
| `T(n) = T(n - 1) + ... + T(n - k)` | O(nk)           | k-step stairs problem               |

## Other Must-Know Patterns

| Problem / Concept                | Time Complexity | Why It Matters                        |
| -------------------------------- | --------------- | ------------------------------------- |
| Backtracking (e.g., N-Queens)    | O(k^n)          | Recursive tree with multiple branches |
| Backtracking with pruning        | Varies          | Sudoku, optimized recursion           |
| Heap (priority queue ops)        | O(n log n)      | Sorting, Dijkstra’s                   |
| Segment Tree / BIT               | O(log n)        | Range queries and updates             |
| Trie (insert/search)             | O(L)            | L = word length                       |
| BFS / DFS on graph               | O(V + E)        | Basic traversal algorithms            |
| Topological Sort (DFS/Kahn)      | O(V + E)        | DAG ordering problems                 |
| Union-Find with path compression | O(α(n))         | Disjoint sets, Kruskal's algorithm    |

## 📘 Master Theorem (Divide & Conquer)

For recurrences of the form:

```
T(n) = aT(n/b) + f(n)
```

* If `f(n) = O(n^log_b(a - ε))` → T(n) = Θ(n^log\_b(a))
* If `f(n) = Θ(n^log_b(a))`     → T(n) = Θ(n^log\_b(a) \* log n)
* If `f(n) = Ω(n^log_b(a + ε))` and regularity condition holds → T(n) = Θ(f(n))

## When Master Theorem Fails

* Non-polynomial `f(n)` (e.g., `f(n) = n log n`) without fitting into case 2
* Recurrences with `T(n-1)` instead of `T(n/b)`
* Uneven recursive subproblem sizes
* Recurrence depends on more than one prior value (e.g., `T(n) = T(n-1) + T(n-2)`)

Use:

* **Recursion Tree**
* **Substitution Method**
* **Guess & Verify (Induction)**

## 🎯 Linear Recurrences (a.k.a. Fibonacci-like)

* Example: `T(n) = a1*T(n-1) + a2*T(n-2)`
* Solve using:

  * Recursion Tree (exponential)
  * DP (O(n))
  * Matrix Exponentiation (O(log n))

---

## How to Practice:

1. Identify recursion type: Tail? Binary tree? Divide & conquer?
2. Translate to recurrence
3. Use pattern matching:

   * Arithmetic sum → O(n^2)
   * Halving input → log n
   * Double calls → exponential
4. Use Master’s Theorem only for divide-and-conquer patterns.
5. Use tabulation or memoization if overlapping subproblems exist.

---

### Classic Intuition Phrases

* “Looks like Fibonacci → O(2^n)”
* “This expands to a sum → O(n^2)”
* “Divide and merge → O(n log n)”
* “Cut in half → O(log n)”
* “Nested loop grid → O(n^2)”
* “DP table fill → O(n) or O(n^2)”

---

Study these patterns and you’ll instantly recognize 80%+ of interview problems!
