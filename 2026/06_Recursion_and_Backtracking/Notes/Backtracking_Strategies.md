# Concept Name: Backtracking Strategies (Permutations, Subsets)

## 1. Intuition and Core Logic
- **Use Case**: Systematically exploring all possible configurations and "backing up" when a path is found to be invalid or complete.
- **Problem Type**: N-Queens, Sudoku solver, or generating all subsets/permutations of a set.
- **Core Pattern**: **Choose -> Explore -> Un-choose (Rollback)**.

---

## 2. State Rollback Correctness
This is the most critical part of backtracking. You must return the shared state (like a `vector` or `string`) to its original condition before returning to the caller.

```cpp
void backtrack(State& s) {
    if (is_goal()) {
        result.push_back(s);
        return;
    }
    for (Choice c : choices) {
        if (is_valid(c)) {
            s.add(c); // Choose
            backtrack(s); // Explore
            s.remove(c); // Un-choose (Rollback)
        }
    }
}
```

---

## 3. Pruning (Efficiency)
- **Logic**: If you can prove a branch of the recursion tree cannot lead to a valid solution, stop and return immediately.
- **Example**: In a sum-to-K problem, if the current sum already exceeds K, there's no need to add more positive numbers.

---

## 4. Common Templates

### Subsets (Power Set)
- For each element, decide: Include or Exclude.
- Complexity: $O(2^N)$.

### Permutations
- Swap elements or use a `visited` array to pick each element exactly once.
- Complexity: $O(N!)$.

---

## 5. Decision Matrix (Read This First)
1. **Need all combinations/subsets?** -> Use standard backtracking.
2. **Tree is too deep?** -> Look for pruning opportunities.
3. **Getting wrong results?** -> Check if your "Un-choose" step perfectly undoes your "Choose" step.
4. **Complexity too high?** -> Check if the problem can be solved with Dynamic Programming or Bitmasking instead.
