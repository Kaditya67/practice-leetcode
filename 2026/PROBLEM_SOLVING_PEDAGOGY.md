# Problem Solving Pedagogy: Systematic Methodology

Solving algorithmic problems is a process of pattern recognition and logical optimization. Follow this structured approach for every problem to build consistent problem-solving skills.

---

## Phase 1: Problem Decomposition (5-10 Minutes)
1. Read the Problem Statement Twice: Ensure you understand the goal and the return type.
2. Analyze Constraints: 
   - N <= 100: O(N^3) or O(N^4) might pass.
   - N <= 10^3: O(N^2) is acceptable.
   - N <= 10^5: O(N log N) or O(N) is required.
   - N <= 10^9: O(log N) or O(1) is likely.
3. Identify Input Edge Cases: Empty arrays, single elements, maximum/minimum possible values, negative numbers.

---

## Phase 2: Logical Brainstorming (10-15 Minutes)
1. Start with Brute Force: Verbally or mentally explain the simplest solution.
2. Identify Bottlenecks: What part of the brute force is slow? (e.g., redundant calculations, unnecessary re-traversals).
3. Apply Known Patterns: Does this look like a Sliding Window? A Monotonic Stack? A Graph traversal?
4. Optimize: Reduce Time/Space complexity by utilizing pre-computed data (Prefix sums, Maps, Sorting).

---

## Phase 3: Dry Run and Verification (5 Minutes)
1. Construct Small Examples: Do not use the examples provided in the problem immediately. Create your own simple cases.
2. Trace the Logic: Manually update your pointers/variables to see if the logic holds.
3. Re-verify Constraints: Ensure your proposed solution fits within the Time and Space limits.

---

## Phase 4: Implementation (The Coding Phase)
1. Modular Code: Use helper functions if a logical block is repeated or complex.
2. Variable Naming: Use descriptive names (e.g., `windowStart` instead of `i`).
3. Comments: Document the "Why", not the "What".

---

## Phase 5: Post-Submission Analysis
1. Analyze Faster Solutions: Even if you passed, read the top solutions.
2. Understand the Gap: Why was their code faster or more concise?
3. Document in Notes: If you learned a new trick, add it to your topic-specific Study Guide.
