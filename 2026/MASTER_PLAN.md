# 2026 DSA MASTER PLAN: Atomic Edition (Acceleration)

Use this as the primary completion checklist across folders `01` to `15`.

## Repository Rules

1. Follow folders in order unless a weekly review explicitly schedules a temporary detour.
2. Read each folder's `STUDY_GUIDE.md` before coding.
3. Store code in `Code/` with:
   `AtomicTopic_ProblemID_Title.cpp`
4. Store notes only in `Notes/`.

## Accuracy-First Progression Gates

Unlock the next folder only if all are true:

1. Current folder exit criteria are complete.
2. Recent first-try acceptance for this folder is >=70%.
3. Every accepted problem has:
   - complexity justification
   - at least one edge-case note

---

## Atomic Checklists + Exit Criteria

### 01. Foundations and STL

- [x] Complexity classes and constraint-based method selection.
- [x] Vector growth, capacity vs size, amortized analysis.
- [x] Iterators and range-based traversal correctness.
- [x] `map` vs `unordered_map` tradeoffs.
- [x] Custom comparator for `priority_queue`.
      Exit criteria:
- [x] Solve 8 to 10 mixed STL and complexity problems.
- [x] Explain why each accepted solution meets time and space limits.

### 02. Mathematics

- [ ] Prime sieve and segmented sieve.
- [ ] GCD/LCM and fast exponentiation.
- [ ] Modular arithmetic and inverse basics.
- [ ] Bitwise XOR pattern use cases.
- [ ] Overflow-safe multiplication patterns.
      Exit criteria:
- [ ] Solve 8 to 10 math/bit problems.
- [ ] Complete at least 2 problems requiring modular arithmetic.

### 03. Arrays and Searching

- [ ] Sliding window (fixed and variable).
- [ ] Two pointers and prefix sum patterns.
- [ ] Kadane and subarray optimization patterns.
- [ ] Binary search classic and on answer.
- [ ] Handling duplicates and boundaries in search problems.
      Exit criteria:
- [ ] Solve 12 problems.
- [ ] At least 4 binary-search based problems accepted.

### 04. Sorting and Greedy

- [ ] Sorting-based transformations.
- [ ] Interval greedy (merge/select/min removals).
- [ ] Greedy proof intuition (local choice to global optimum).
- [ ] Custom sorting with stable tie-breakers.
- [ ] Counterexample-based greedy validation.
      Exit criteria:
- [ ] Solve 10 greedy/sorting problems.
- [ ] Document one failed greedy idea and why it failed.

### 05. Strings

- [ ] Frequency map and counting patterns.
- [ ] Two pointers on strings.
- [ ] Rolling/hash awareness (conceptual).
- [ ] Pattern matching basics and substring constraints.
- [ ] Palindrome expansion/two-pointer checks.
      Exit criteria:
- [ ] Solve 10 string problems.
- [ ] Keep edge-case notes for empty, repeated, and Unicode-like inputs.

### 06. Recursion and Backtracking

- [ ] Base case design and recursion tree reasoning.
- [ ] Subset, permutation, and combination generation.
- [ ] Pruning rules and early exit conditions.
- [ ] State rollback correctness.
- [ ] Backtracking time complexity awareness.
      Exit criteria:
- [ ] Solve 8 recursion/backtracking problems.
- [ ] Explain one pruning strategy that reduced runtime.

### 07. Linked Lists

- [ ] Fast/slow pointer patterns.
- [ ] Reverse list and k-group transformations.
- [ ] Merge sorted lists and intersection detection.
- [ ] Dummy-node technique.
- [ ] Cycle detection and entry-point logic.
      Exit criteria:
- [ ] Solve 8 linked-list problems.
- [ ] Complete 3 problems in under 20 minutes each by re-solve.

### 08. Stacks and Queues

- [ ] Monotonic stack for next greater/smaller.
- [ ] Valid parenthesis and expression parsing basics.
- [ ] Queue-based BFS mental model.
- [ ] Deque for sliding window maximum.
- [ ] Stack simulation for recursive behavior.
      Exit criteria:
- [ ] Solve 8 stack/queue problems.
- [ ] Solve at least 2 monotonic-stack problems without hints.

### 09. Trees and BST

- [ ] DFS traversals (pre/in/post) and level-order BFS.
- [ ] Tree recursion on height, diameter, path sum.
- [ ] BST invariants and validation logic.
- [ ] LCA and ancestor reasoning.
- [ ] Serialization/deserialization awareness.
      Exit criteria:
- [ ] Solve 12 tree/BST problems.
- [ ] Explain recursion state for one hard tree problem.

### 10. Heaps and Priority Queues

- [ ] Min/max heap usage and k-based problems.
- [ ] Top-k frequency and merge-k structures.
- [ ] Custom comparator correctness.
- [ ] Heap + greedy combinations.
- [ ] Streaming median concept.
      Exit criteria:
- [ ] Solve 8 heap problems.
- [ ] Complete at least 2 top-k style problems with clean complexity proof.

### 11. Dynamic Programming

- [ ] 1D DP transition design.
- [ ] 2D DP grid/string patterns.
- [ ] 0/1 and unbounded knapsack.
- [ ] DP on trees/state compression awareness.
- [ ] Memoization vs tabulation tradeoffs.
      Exit criteria:
- [ ] Solve 14 DP problems.
- [ ] Document state, transition, base case for each solved DP problem.

### 12. Graphs

- [ ] BFS/DFS traversals.
- [ ] Topological sort and DAG reasoning.
- [ ] Shortest path (Dijkstra/Bellman-Ford overview).
- [ ] MST basics (Kruskal/Prim).
- [ ] DSU for connectivity.
      Exit criteria:
- [ ] Solve 12 graph problems.
- [ ] Correctly choose between BFS, Dijkstra, and DSU in notes.

### 13. Tries and Segment Trees

- [ ] Trie insert/search/prefix.
- [ ] Bitwise trie intuition (optional advanced).
- [ ] Segment tree build/query/update.
- [ ] Lazy propagation awareness.
- [ ] Compare Fenwick vs Segment Tree use cases.
      Exit criteria:
- [ ] Solve 6 to 8 problems.
- [ ] Implement one segment tree from scratch without copy-paste.

### 14. Advanced Topics

- [ ] Sweep line and event sorting basics.
- [ ] Binary lifting awareness.
- [ ] Advanced DP patterns overview.
- [ ] String algorithms overview (KMP/Z optional).
- [ ] Meet-in-the-middle awareness.
      Exit criteria:
- [ ] Solve 6 problems with at least 2 advanced constraints cases.
- [ ] Record why the chosen advanced pattern was required.

### 15. Contests and Assessments

- [ ] Weekly timed simulation (2 to 3 problems).
- [ ] Post-contest error taxonomy log.
- [ ] Speed rerun from failed contest questions.
- [ ] Weak-topic remediation assignment.
- [ ] Next-week topic lock.
      Exit criteria:
- [ ] Complete 1 timed simulation every week.
- [ ] Show week-over-week non-decreasing accuracy or documented remediation.

---

## Completion Standard Per Problem

- [ ] Complexity justification added.
- [ ] At least one edge-case note recorded.
- [ ] If >45 minutes or hint used, problem logged in `SPACED_REPETITION_LOG.md`.
