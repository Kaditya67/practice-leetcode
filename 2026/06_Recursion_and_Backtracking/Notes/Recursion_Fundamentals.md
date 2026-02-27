# Concept Name: Recursion Fundamentals (Base Cases, Trees)

## 1. Intuition and Core Logic
- **Use Case**: Solving a problem by breaking it down into smaller, identical sub-problems.
- **Problem Type**: Tree traversals, mathematical sequences (Factorial, Fibonacci), or any problem with a repetitive nested structure.
- **The Mental Model**: Think of the "Call Stack". Each function call waits for the next one to finish before it can resume and return its own result.

---

## 2. The Anatomy of a Recursive Function
1. **Base Case**: The simplest version of the problem that can be solved directly. This stops the recursion.
2. **Recursive Step**: The call to the function itself with a "smaller" or "simpler" version of the input.
3. **Combination**: Using the result of the recursive call to form the final result.

```cpp
int factorial(int n) {
    if (n <= 1) return 1; // Base Case
    return n * factorial(n - 1); // Recursive Step + Combination
}
```

---

## 3. Recursion Trees and Stack Overflow
- **Recursion Tree**: A visual representation of all function calls. Useful for estimating complexity.
- **Stack Overflow**: Occurs when recursion goes too deep (missing base case or too many calls). 
- **Rule of Thumb**: For most systems, a depth of $10^5$ is safe, but $10^6$ might crash the stack.

---

## 4. Decision Matrix (Read This First)
1. **Problem has a recursive structure?** -> Use recursion.
2. **Need to explore all possibilities?** -> Think of a recursion tree.
3. **Memory is extremely tight?** -> Consider iterating with a manual stack to avoid function call overhead.
4. **Base case reached?** -> Ensure every possible path in your code hits a base case.
