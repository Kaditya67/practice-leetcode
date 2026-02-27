# Concept Name: Linear Optimization (Prefix Sums, Kadane's)

## 1. Intuition and Core Logic
- **Use Case**: Reducing $O(N^2)$ or $O(N^3)$ brute-force subarray queries into $O(1)$ or $O(N)$ operations.
- **Problem Type**: Finding range sums, maximum subarray sums, or counting subarrays with a specific property.

---

## 2. Prefix Sums (Range Queries in $O(1)$)

### 1D Prefix Sum
- **Precompute**: $P[i] = A[0] + A[1] + ... + A[i-1]$.
- **Query**: $Sum(L, R) = P[R+1] - P[L]$.
- **Complexity**: $O(N)$ build, $O(1)$ query.

### 2.2 2D Prefix Sum (Matrix)
- **Precompute**: $P[i][j]$ is the sum of the rectangle from $(0,0)$ to $(i,j)$.
- **Query**: $Sum((r1, c1), (r2, c2)) = P[r2][c2] - P[r1-1][c2] - P[r2][c1-1] + P[r1-1][c1-1]$.
- **Complexity**: $O(NM)$ build, $O(1)$ query.

---

## 3. Kadane's Algorithm (Max Subarray Sum)
- **Logic**: At each step, decide whether to extend the current subarray or start a new one from the current element.
- **Transition**: `current_sum = max(A[i], current_sum + A[i])`.
- **Global Result**: `best_sum = max(best_sum, current_sum)`.
- **Complexity**: $O(N)$ time, $O(1)$ space.

---

## 4. Prerequisite Map
- **STL Fluency**: Using `std::vector` for precomputation.
- **Complexity Analysis**: Understanding the shift from $O(N^2)$ to $O(N)$.

---

## 5. Decision Matrix (Read This First)
1. **Need multiple range sum queries?** -> Use Prefix Sums.
2. **Need max sum of a contiguous subarray?** -> Use Kadane's Algorithm.
3. **Problem involves 2D grids?** -> Consider 2D Prefix Sums.
4. **Need to count subarrays with sum $K$?** -> Use Prefix Sum + Hash Map (Frequency Map).
