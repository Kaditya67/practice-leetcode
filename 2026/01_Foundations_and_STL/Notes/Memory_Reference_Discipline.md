# Concept Name: Pass-by-Reference and Memory Discipline

## 1. Intuition and Core Logic
- **The Problem**: In C++, if you pass a large container (like a `vector<int>` with 10^6 elements) to a function without a reference, the compiler creates a **complete copy** of it. This turns an $O(1)$ function call into an $O(N)$ operation, often causing a TLE (Time Limit Exceeded).
- **The Solution**: Use **Pass-by-Reference** to tell the function to look at the original data rather than making a copy.

---

## 2. The Three Ways to Pass Data

### 2.1 Pass by Value
```cpp
void process(vector<int> a) { // SLOW: Creates a full copy
    // ...
}
```
- **When to use**: Only for primitive types like `int`, `char`, `bool`, or `double`.

### 2.2 Pass by Reference (Mutable)
```cpp
void process(vector<int>& a) { // FAST: Uses original data
    a[0] = 100; // Modifies the original vector outside
}
```
- **When to use**: When the function **needs** to modify the input (e.g., in Recursive Backtracking).

### 2.3 Pass by Const Reference (Best Default)
```cpp
void process(const vector<int>& a) { // FAST: Uses original data, but read-only
    // a[0] = 100; // ERROR: Compiler won't let you change it
}
```
- **When to use**: For **every** large object (Strings, Vectors, Maps) that you only need to read. This is the gold standard for DSA.

---

## 3. Memory Discipline (The CP Mindset)
In competitive programming, you often have a strict memory limit (e.g., 256MB).

- **Global vs. Local**: Large arrays (e.g., `int arr[1000000]`) should be declared **globally** or using `std::vector`. Local arrays are stored on the **Stack**, which is much smaller than the **Heap** and can cause a crash.
- **Reserve Space**: If you know you'll need $N$ elements, use `v.reserve(N)` to avoid multiple reallocations.
- **Clear vs. Re-allocate**: In problems with multiple test cases, use `v.clear()` instead of declaring a new vector inside the loop to reuse the allocated memory capacity.

---

## 4. Decision Matrix (Read This First)
1. **Passing a large vector or string?** -> Use `const string&` or `vector<int>&`.
2. **Function needs to change the original?** -> Use `&`.
3. **Declared a huge array inside a function?** -> Move it to global scope or use `static`.
4. **Getting TLE on a recursive function?** -> Check if you are passing the state "by value" instead of "by reference".
