# DEBUGGING MANUAL: Rational Error Resolution

Never "guess" what is wrong with your code. Guessing wastes time and builds bad habits. Follow this workflow when your code fails.

---

## 1. Wrong Answer (WA)
Your logic is fundamentally flawed or you missed an edge case.
1. Read the failing test case carefully.
2. Dry run your code manually on paper with that specific test case.
3. Check 0, negative numbers, maximum constraints, and empty arrays.
4. Are you using `int` where you need `long long`? (Integer overflow triggers WA).

## 2. Time Limit Exceeded (TLE)
Your complexity is too high, or you have an infinite loop.
1. Check your `while` loops. Is the counter actually incrementing/decrementing?
2. Did you pass large data structures by value instead of reference? (e.g., `vector<int> nums` instead of `vector<int>& nums`). This causes an $O(N)$ copy on every function call.
3. Review constraints. If $N = 10^5$ and your loop is nested $O(N^2)$, it will TLE.

## 3. Runtime Error / Segmentation Fault
You accessed memory you do not own.
1. Are you accessing an array index $< 0$ or $\ge N$?
2. Is your vector empty when you call `.front()` or `.back()`?
3. In trees or linked lists, did you check `if (node == nullptr)` before calling `node->val`?
4. In recursion, is your base case missing or incorrect? (Causes stack overflow).

---

## 🛠️ The "Rubber Duck" Isolation Method
If you have stared at the code for 15 minutes and cannot find the bug:
1. Explain your code out loud, line by line, to an imaginary rubber duck.
2. Comment out half of your logic. Does the core still run? Binary-search your bug.
3. Insert simple `cout << var << endl;` statements at logical checkpoints to ensure variables hold the values you expect them to hold.
