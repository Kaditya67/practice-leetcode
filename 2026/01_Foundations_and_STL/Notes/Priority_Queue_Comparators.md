# Concept Name: Custom Comparators for priority_queue

## 1. Intuition and Core Logic
- **Definition**: By default, C++ `std::priority_queue` is a **Max-Heap** (it keeps the largest element at the top).
- **The Challenge**: Often in interviews, you need a **Min-Heap** (smallest at top) or a heap based on custom logic (e.g., sort by frequency).
- **The Trap**: For `std::sort`, `a < b` results in ascending order. But for `priority_queue`, the logic is **inverted**. A comparator that returns `true` for `a < b` will make `b` stay "higher" priority, resulting in a **Max-Heap**.

## 2. Syntax Overview

### 2.1 The Built-in Min-Heap
```cpp
// Standard Max-Heap (Top is largest)
priority_queue<int> maxHeap;

// Standard Min-Heap (Top is smallest)
priority_queue<int, vector<int>, greater<int>> minHeap;
```

### 2.2 The Custom Struct Comparator (Most Common)
```cpp
struct MyCompare {
    bool operator()(int a, int b) {
        // Return true if 'a' should be BELOW 'b' in the heap.
        // To make a Min-Heap (smallest at top), we want 'a' below 'b' if a > b.
        return a > b; 
    }
};

priority_queue<int, vector<int>, MyCompare> customHeap;
```

---

## 3. The "Opposite Intuition" Strategy
To never get confused again, use this rule:
- **`std::sort`**: If `cmp(a, b)` is true, `a` comes **first**.
- **`std::priority_queue`**: If `cmp(a, b)` is true, `a` comes **last** (stays at the bottom).

**Mnemonic**: In a heap, the `operator()` defines who is "weaker". If `a > b` is true, then `a` is weaker and sinks to the bottom, leaving the smaller `b` at the top.

---

## 6. Modern C++ Syntax Breakdown: Lambdas and `decltype` (Top-K Frequency)

If your map is `freq[val]`, and you want small frequencies at the top (Min-Heap), you use this "Modern" syntax to avoid writing a separate `struct`:

```cpp
// 1. Define the Lambda (A function without a name)
auto cmp = [&](int a, int b) {
    // [&] means "capture everything by reference" 
    // This allows the function to "see" the freq map outside itself
    return freq[a] > freq[b]; 
};

// 2. Declare the Queue
// decltype(cmp) tells the compiler: "Use the same secret type as my cmp variable"
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
```

### Why we need `decltype(cmp)`:
Because every lambda you create has a unique, hidden type that only the compiler knows. You can't just type `priority_queue<int, vector<int>, lambda>` because `lambda` isn't a keyword. You use `decltype` to say: *"Whatever that secret type is, use it here!"*

---

## 7. Reflections and Variations
- If you only need a Min-Heap for integers, just use `greater<int>`. Don't overcomplicate.
- Remember that `priority_queue` is inside `<queue>`.
- **Complexity**: `push()` and `pop()` are $O(\log K)$ where $K$ is the heap size. `top()` is $O(1)$.

