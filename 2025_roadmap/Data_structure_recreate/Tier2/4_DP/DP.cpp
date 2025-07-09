// | Concept                        | Description                                                   |
// | ------------------------------ | ------------------------------------------------------------- |
// | Memoization                    | Top-down + recursion + cache (usually `dp[]`)                 |
// | Tabulation                     | Bottom-up + iteration + `dp[]` array                          |
// | Space Optimized Tabulation     | Tabulation with **reduced space**, storing only recent states |


// 1. Understanding Problem Overlaps & Optimal Substructure
// Overlapping Subproblems: DP is used when problems can be broken into subproblems which are solved multiple times.
// Optimal Substructure: The optimal solution to the problem can be constructed from optimal solutions of its subproblems.
// Example: Fibonacci, shortest paths, knapsack.

// 2. Recursion & Backtracking
// Most DP problems start as recursive solutions.
// Knowing how to write clean recursion with base cases and recursive calls is essential.
// DP is essentially recursion + memoization or tabulation.

// 3. State & State Transition
// Learn to define your DP state(s) — what parameters uniquely identify subproblems? (e.g., index, remaining capacity, current sum).
// Understand how to transition from one state to another based on choices.
// Example: In knapsack, state can be (index, remaining_weight) and transitions depend on whether you pick or skip an item.

// 4. Memoization vs Tabulation
// Memoization: Top-down, recursion + cache results.
// Tabulation: Bottom-up, iterative filling of DP table.
// Understand when and why to prefer one over the other.

// 5. Handling Multiple Dimensions
// Many problems need 2D or even 3D DP arrays.
// Practice indexing and interpreting these dimensions clearly.

// 6. Space Optimization Techniques
// When DP depends only on previous states, learn to reduce space from O(n) or O(n²) to O(1) or O(n).
// Rolling arrays, iterative approaches.

// 7. Practice with Classic Problems First
// Fibonacci, Climbing Stairs, Coin Change, Knapsack, LIS.
// These cover different DP types: counting ways, optimization, subsequences.

// 8. Patience and Debugging Skills
// DP can be tricky with indexing and states; patience is key.
// Use print/debug statements to understand DP table filling.
// Visualize the problem and states using diagrams or tables.