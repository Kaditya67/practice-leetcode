# Masterclass: C++ Custom Comparators

Understanding comparators is the difference between struggling with syntax and writing elegant STL code. Here are the core concepts and the mistakes to avoid.

## 1. The Core Concept: "Strict Weak Ordering"

A comparator should answer: **"Should `a` come AFTER `b`?"**

- If `true`: `a` is "lesser" priority/value than `b`.
- If `false`: `a` is "greater" or equal priority/value than `b`.

## 2. Global Rule: Sort vs. Priority Queue

The biggest trap in C++ is that the logic is **inverted** between `std::sort` and `std::priority_queue`.

| Feature        | `std::sort`                 | `std::priority_queue`                        |
| :------------- | :-------------------------- | :------------------------------------------- |
| **Default**    | Ascending (Min at start)    | Descending (Max at top)                      |
| **Logic**      | `a < b` means `a` is FIRST. | `a < b` means `a` is LOWER priority (sinks). |
| **To get Min** | `return a < b;`             | `return a > b;`                              |

---

## 3. Common Pitfalls (From your attempts)

### ❌ Problem 1: Putting data inside the Comparator struct

A comparator is a **rule**, not a data container. It should not hold `dist` or `coord`.

```cpp
// WRONG
struct MyCmp {
    int dist; // Comparators shouldn't have local state like this
    bool operator()(Point a, Point b) { ... }
};

// RIGHT
struct MyCmp {
    bool operator()(const Point& a, const Point& b) const {
        return a.dist < b.dist;
    }
};
```

### ❌ Problem 2: Missing `const` and Reference

For efficiency and compatibility, always pass by `const reference` and mark the function `const`.

```cpp
bool operator()(const Type& a, const Type& b) const { ... }
```

### ❌ Problem 3: Multi-argument `push`

`pq.push()` only takes **one** element. If you want to store a distance AND a point, you must bundle them into a `struct` or a `std::pair`.

---

## 4. Different Implementation Styles

### A. The Custom Struct (Best for reuse)

```cpp
struct Point {
    int x, y, distSq;
};

struct ComparePoints {
    bool operator()(const Point& a, const Point& b) const {
        // MAXX-HEAP: Largest distSq at top.
        // We want this for "K Closest" because we pop the farthest.
        return a.distSq < b.distSq;
    }
};

priority_queue<Point, vector<Point>, ComparePoints> pq;
```

### B. The Lambda (Best for one-off logic)

```cpp
auto cmp = [](const vector<int>& a, const vector<int>& b) {
    int d1 = a[0]*a[0] + a[1]*a[1];
    int d2 = b[0]*b[0] + b[1]*b[1];
    return d1 < d2; // Max-heap
};
priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
```

---

## 5. Decision Matrix for "K Closest"

To find the **Smallest K** elements:

1. **Approach 1: Max-Heap of size K (Optimal)**
   - Logic: Keep the "biggest of the smalls" at the top.
   - If new element < top, `pop()` top and `push()` new.
   - Comparator: `a < b` (Max-heap).

2. **Approach 2: Min-Heap of all N (Easy but slower)**
   - Logic: Push everyone, then `pop()` K times.
   - Comparator: `a > b` (Min-heap).
