# Concept Name: STL Trigger Patterns and Intuition

## 1. Complexity and N-Constraints
In competitive programming, the size of $N$ (the input size) dictates your algorithm.
- **$N \approx 10^5$ to $10^6$**: You need $O(N)$ or $O(N \log N)$ logic. 
- **STL Trigger**: If $N$ is this large and you need to check existence, use `std::unordered_set` or `std::unordered_map` ($O(N)$ total). If you need sorting or ordered keys, use `std::sort` or `std::map` ($O(N \log N)$ total).

---

## 2. Fast Lookup vs. Ordered Traversal
Choosing the right container is about understanding the "Search vs. Order" trade-off.

### Need Fast Lookup ($O(1)$ Average)
- **Container**: `std::unordered_map` / `std::unordered_set`.
- **Trigger**: "Does element X exist?", "What is the frequency of Y?", "Have I seen this state before?".

### Need Ordered Traversal ($O(\log N)$ Operations)
- **Container**: `std::map` / `std::set`.
- **Trigger**: "Find the smallest element larger than K", "Print elements in sorted order", "Maintain a dynamic sorted list".

---

## 3. Dynamic Top-K (The Priority Pattern)
- **Container**: `std::priority_queue`.
- **Trigger**: "What is the current maximum/minimum?", "Process elements in order of priority", "Dynamic inserts where we only care about the best element".
- **Intuition**: If the problem involves "The $K$ best", "Merging $K$ files", or "Dijkstra's", the `priority_queue` is the standard tool.

---

## 4. Decision Matrix (The "Cheat Sheet")
1. **$N$ is $10^6$ and I need to count things?** -> Use `unordered_map` (Avoid `map` to prevent TLE).
2. **Need to find the 'closest' value?** -> Use `std::set` with `lower_bound`.
3. **Inserting elements and always need the max?** -> Use `priority_queue`.
4. **Memory is tight but $N$ is large?** -> Consider a frequency array (if keys are small) or `reserve()` your vectors.
