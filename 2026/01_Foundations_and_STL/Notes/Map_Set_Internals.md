# Concept Name: Map and Set Internals (Ordered vs Unordered)

## 1. The Core Choice
In C++, you must choose between **Ordered** (Tree-based) and **Unordered** (Hash-based) containers. Choosing correctly prevents Time Limit Exceeded (TLE) errors.

| Feature | `std::map` / `std::set` | `std::unordered_map` / `std::set` |
| :--- | :--- | :--- |
| **Data Structure** | Red-Black Tree (Balanced BST) | Hash Table (Buckets) |
| **Avg Complexity** | $O(\log N)$ | $O(1)$ |
| **Worst-case** | $O(\log N)$ | $O(N)$ (Rare collisions) |
| **Iteration Order** | **Sorted** by Key | **Random** / No order |
| **Requirement** | Key must support `<` | Key must be Hashable |

---

## 2. Essential API: The `operator[]` Trap
In Maps, `mp[key]` does not just "look up" a value—it **mutates** the map if the key is missing.

- **Bad (Side Effects)**: `if (mp[key] == 0)` will insert the key into the map if it wasn't there.
- **Good (Safe Check)**: `if (mp.find(key) != mp.end())` checks existence without inserting.
- **Frequency counting**: `mp[key]++` is the standard and safe way to count occurrences.

---

## 3. Ordered Container "Superpowers"
Use `std::map` or `std::set` when you need these specific tree-based operations that Unordered containers **cannot** do:
- **`lower_bound(k)`**: Finds the first element $\ge k$.
- **`upper_bound(k)`**: Finds the first element $> k$.
- **Sorted Traversal**: `for (auto const& [key, val] : mp)` will always visit keys in increasing order.

---

## 4. Decision Matrix (Read This First)
1. **Need speed and order doesn't matter?** -> Use `std::unordered_map`. (90% of frequency counting problems).
2. **Need elements to be sorted?** -> Use `std::map`.
3. **Need to find the "next closest" value?** -> Use `std::map` (for `lower_bound`).
4. **Handling duplicates?** -> Use `std::multiset` or `std::map<int, int>` (key -> count).

---

## 5. Pro-Tip: Memory & Constraints
- If $N = 10^5$, $O(N \log N)$ using `std::map` is $\approx 1.7 \times 10^6$ operations, which is **safe** (well under the $10^8$/sec limit).
- `unordered_map` has higher memory overhead than a raw array. If you are very tight on memory, be careful.
