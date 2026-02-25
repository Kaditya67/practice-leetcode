# 2026 DSA CURRICULUM: Dependency Map (01 to 15)

This curriculum is the content truth for what to learn, when to learn it, and why the order matters.

## Learning Profile Defaults
- Current level: Easy strong, Medium weak.
- Training style: Accuracy-first.
- Goal: build stable Medium performance first, then increase speed.

## Timing Reality (March 2026)
- Stage A (Weeks 1 to 2): prioritize correctness and consistency over speed.
  - Medium target: median <=35 minutes.
  - Hard target: not enforced yet.
- Stage B (Weeks 3 and later): controlled speed push after stability.
  - Medium target: move from <=35 toward <=30 minutes.
  - Hard target: activate only after Medium stability is reached.

---

## Canonical Dependency Chain
`01 -> 02 -> 03 -> 04 -> 05 -> 06 -> 07 -> 08 -> 09 -> 10 -> 11 -> 12 -> 13 -> 14 -> 15`

Secondary prerequisites:
- `11` depends heavily on `06` and `09`.
- `12` depends on `08`, `09`, and STL fluency from `01`.
- `13` depends on tree recursion awareness from `09`.

---

## Folder-by-Folder Syllabus

### 01. Foundations and STL
- Big-O reasoning from constraints.
- STL containers, iterators, comparator mechanics.
- Memory and pass-by-reference discipline.
Why now:
- All later optimization depends on this base.

### 02. Mathematics
- Number theory basics, sieve, modular arithmetic, fast power.
- Bitwise operations and overflow-safe arithmetic.
Why now:
- Needed for many array, greedy, graph, and contest problems.

### 03. Arrays and Searching
- Sliding window, two pointers, prefix sums, binary search on answer.
Why now:
- Highest interview pattern frequency and best medium-level ramp.

### 04. Sorting and Greedy
- Sorting transforms, interval patterns, greedy proof intuition.
Why now:
- Converts many brute-force thoughts into optimal patterns.

### 05. Strings
- Frequency maps, pointer strategies, pattern matching basics.
Why now:
- Common in interviews and builds careful edge-case thinking.

### 06. Recursion and Backtracking
- State trees, pruning, rollback correctness.
Why now:
- Required foundation for trees and dynamic programming depth.

### 07. Linked Lists
- Pointer manipulation patterns, cycle logic, in-place transforms.
Why now:
- Sharpens pointer correctness and interview reliability.

### 08. Stacks and Queues
- Monotonic stack/queue, deque windows, expression basics.
Why now:
- Core for linear-time optimizations and graph traversal intuition.

### 09. Trees and BST
- DFS/BFS traversals, BST invariants, recursion over structure.
Why now:
- Bridge topic before advanced recursion-heavy DP and graphs.

### 10. Heaps and Priority Queues
- Top-k problems, stream processing, heap-driven greedy.
Why now:
- High-yield pattern for interview and contest tasks.

### 11. Dynamic Programming
- State definition, transitions, memoization/tabulation, knapsack family.
Why now:
- Depends on prior recursion and tree-state understanding.

### 12. Graphs
- BFS/DFS, shortest path, MST, DSU, topo sort.
Why now:
- Uses stacks/queues, recursion thinking, and optimization habits.

### 13. Tries and Segment Trees
- Prefix data structures and range-query/update structures.
Why now:
- Advanced data-structure layer after trees/graphs fluency.

### 14. Advanced Topics
- Binary lifting, sweep line, meet-in-the-middle, advanced DP/string overviews.
Why now:
- Requires broad pattern base and strong implementation confidence.

### 15. Contests and Assessments
- Timed mixed sets, post-contest analysis, weak-topic repair loops.
Why now:
- Integrates all previous folders into speed + accuracy performance.

---

## Promotion Rule Between Folders
Move to the next folder only when:
1. Exit criteria are complete in `MASTER_PLAN.md`.
2. Recent first-try acceptance is >=70% for that folder's set.
3. You can explain complexity and one edge case for each accepted solution.
