# Dynamic Programming Cheat Sheet

## 1. Memoization vs Tabulation
| Use Case                    | When to Use                              | Notes                                 |
|-----------------------------|-----------------------------------------|---------------------------------------|
| Memoization (Top-Down)       | Problems with overlapping subproblems, easier for recursion | Easy to implement, but uses stack space |
| Tabulation (Bottom-Up)       | Problems where iterative approach is feasible | More efficient, no recursion overhead  |
| Space Optimization           | When only few previous states needed | Reduce from O(n) or O(n²) to O(1) or O(n) |

---

## 2. 1D DP Problems
| Problem                     | DP State/Transition                                      | Notes                                     |
|-----------------------------|---------------------------------------------------------|-------------------------------------------|
| Fibonacci / Climbing Stairs  | dp[i] = dp[i-1] + dp[i-2]                              | Classic base case                         |
| House Robber                 | dp[i] = max(dp[i-1], dp[i-2] + nums[i])                | No two adjacent picks                      |
| Coin Change I (min coins)    | dp[amount] = min(dp[amount - coin] + 1)                 | Find minimum number of coins               |
| Coin Change II (total ways)  | dp[amount] += dp[amount - coin]                          | Count total combinations                   |

---

## 3. 2D DP Problems
| Problem                     | DP State/Transition                                      | Notes                                     |
|-----------------------------|---------------------------------------------------------|-------------------------------------------|
| Grid Unique Paths            | dp[i][j] = dp[i-1][j] + dp[i][j-1]                      | Count ways in grid movement                |
| Min Cost Path               | dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i][j-1])     | Minimum path cost                          |
| Subset Sum                  | dp[i][sum] = dp[i-1][sum] or dp[i-1][sum - arr[i]]       | Check if subset with sum exists            |
| Equal Partition             | Reduce to subset sum problem                             | Partition array into two equal sum parts  |

---

## 4. Knapsack Variants
| Problem                     | DP State/Transition                                      | Notes                                     |
|-----------------------------|---------------------------------------------------------|-------------------------------------------|
| 0/1 Knapsack                | dp[i][w] = max(dp[i-1][w], dp[i-1][w - wt[i]] + val[i]) | Each item chosen once                      |
| Unbounded Knapsack          | dp[i][w] = max(dp[i-1][w], dp[i][w - wt[i]] + val[i])   | Items can be chosen infinite times         |
| Rod Cutting                 | Similar to unbounded knapsack                            | Max revenue by cutting rod pieces          |
| Coin Change I (min coins)   | Min coins to form sum                                   | Min number of coins                         |
| Coin Change II (total ways) | Count ways to form sum                                  | Count all combinations                      |

---

## 5. Longest Increasing Subsequence (LIS) and Variants
| Problem                     | DP State/Transition                                      | Complexity     | Notes                                 |
|-----------------------------|---------------------------------------------------------|----------------|-------------------------------------|
| LIS (O(n²))                 | dp[i] = max of dp[j]+1 if arr[i] > arr[j], j < i         | O(n²) time     | Classic DP solution                  |
| LIS (O(n log n))            | Use binary search on tails array                         | O(n log n)     | Efficient for large inputs           |
| LDS (Longest Decreasing)    | Same as LIS but with reversed comparison                 | O(n²) or O(n log n) | Useful for bitonic subsequence        |
| LBS (Bitonic Subsequence)   | Combine LIS + LDS for each index                          | O(n²)          | Sequence first increasing then decreasing |
| Russian Doll Envelopes      | Sort envelopes and LIS on heights                         | O(n log n)     | 2D LIS variant                      |
| Building Bridges            | Sort pairs and LIS on second dimension                    | O(n log n)     | Similar to Russian Doll             |
| Max Sum Increasing Subseq   | dp[i] = max sum with increasing property                 | O(n²)          | Variation tracking sums             |

---

## 6. Subset DP (Subset Sum and Variants)
| Problem                     | DP State/Transition                                      | Notes                                  |
|-----------------------------|---------------------------------------------------------|--------------------------------------|
| Subset Sum                  | dp[i][sum] = dp[i-1][sum] or dp[i-1][sum - arr[i]]       | Find if subset sums to target        |
| Equal Partition             | Check if total sum/2 subset exists                        | Partition problem                    |
| Count subsets with sum K    | Count dp[i][sum] = dp[i-1][sum] + dp[i-1][sum - arr[i]]  | Count subsets with given sum         |

---

## Tips to Choose DP Approach:

| Scenario                       | Approach                              |
|--------------------------------|-------------------------------------|
| State depends on index & sum   | Use 2D DP (e.g. subset, knapsack)  |
| State depends on previous few states | Use 1D DP or rolling arrays         |
| Need number of ways (counting) | Add states from all possible transitions |
| Need minimum/maximum cost       | Use min/max with transitions         |
| Longest increasing subsequence | Use LIS DP or binary search method   |
| Problem fits recursion naturally | Memoization preferred (top-down)    |
| Need fast iterative solution    | Tabulation (bottom-up) preferred    |

---

## Space Optimization Tricks
- Use rolling arrays if `dp[i]` depends only on `dp[i-1]` or limited previous states.
- For subset sum, use 1D dp with reversed iteration.
- For LIS counting, binary search allows O(n log n) with O(n) space.

---

# Summary
- Start with memoization for clarity, switch to tabulation for efficiency.
- Identify the **state variables** carefully.
- Use binary search optimization when applicable (LIS, Coin Change variants).
- Use subset DP for partition/sum-related problems.
- Use classical knapsack patterns for weight-value selection problems.

---

