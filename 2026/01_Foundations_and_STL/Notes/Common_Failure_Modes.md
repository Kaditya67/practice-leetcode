# Concept Name: Common Failure Modes in STL

## 1. Using `unordered_map` when ordering is required
- **The Pitfall**: `std::unordered_map` provides $O(1)$ average lookup but loses all sense of key order. 
- **The Failure**: If a problem requires you to find the "next larger element" or "smallest element in a range", `unordered_map` will fail.
- **The Fix**: Use `std::map` ($O(\log N)$) when you need to navigate keys using `lower_bound` or `upper_bound`.

---

## 2. Copying Large Vectors by Value
- **The Pitfall**: Passing a `std::vector` or `std::string` to a function without the `&` symbol.
- **The Failure**: The entire container is duplicated in memory for every function call. In recursive functions, this leads to $O(N \times \text{depth})$ time complexity, causing a guaranteed TLE.
- **The Fix**: Always pass by `const &` (read-only) or `&` (mutable).

---

## 3. Ignoring Iterator Invalidation
- **The Pitfall**: Modifying a container (adding/removing elements) while iterating through it.
- **The Failure**: 
    - **`std::vector`**: Adding an element can trigger a reallocation, making **all** existing iterators/pointers/references garbage.
    - **`std::vector` / `std::deque`**: Removing an element invalidates all iterators after the point of removal.
    - **`std::map` / `std::set`**: Removing an element only invalidates the iterator to that specific element.
- **The Fix**: 
    - When erasing, use the return value of `.erase(it)` to get the next valid iterator.
    - Avoid `push_back` inside a loop that uses iterators unless you know the capacity is sufficient or you restart the iteration.

```cpp
// Correct way to erase while iterating
for (auto it = v.begin(); it != v.end(); ) {
    if (should_erase(*it)) {
        it = v.erase(it); // Returns next valid iterator
    } else {
        ++it;
    }
}
```

---

## 4. Decision Matrix (Read This First)
1. **Recursion depth is high?** -> Check if state is passed by reference.
2. **Erasing from a vector?** -> Be extremely careful with index/iterator shifts.
3. **Values are sorted but I'm using a hash table?** -> Switch to `std::map`.
4. **Getting random crashes?** -> Check for iterator invalidation or out-of-bounds access.
