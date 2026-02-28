# Concept: std::list (Doubly Linked List)

You mentioned we missed `list` (assuming it was a typo for "lust"!). `std::list` is a critical container when O(1) removals and insertions are required at any position.

## 1. Why `std::list`?

Unlike `std::vector`, which is a contiguous array, `std::list` is a **Doubly Linked List**.

| Feature                    | `std::vector`           | `std::list`             |
| :------------------------- | :---------------------- | :---------------------- |
| **Random Access**          | $O(1)$ (`v[i]`)         | $O(N)$ (Must traverse)  |
| **Insert/Delete (Start)**  | $O(N)$                  | $O(1)$                  |
| **Insert/Delete (Middle)** | $O(N)$                  | $O(1)$ (with iterator)  |
| **Iterator Invalidation**  | High (capacity changes) | Low (only deleted node) |

---

## 2. Core Syntax

```cpp
#include <list>

list<int> l;
l.push_back(10);  // [10]
l.push_front(20); // [20, 10]

// Iterators are used to navigate
auto it = l.begin();
l.insert(it, 30); // [30, 20, 10]
```

---

## 3. The Power Move: `std::list::splice`

This is why we use `list` for LRU Cache. `splice` moves elements from one position to another **without copying or reallocating memory**. It just updates pointers.

```cpp
// Move element pointed to by 'it' to the front of the list
l.splice(l.begin(), l, it);
```

- **Complexity**: $O(1)$
- **Use Case**: In LRU Cache, when a key is accessed, we "splice" it to the front to mark it as Most Recently Used.

---

## 4. Behind the Scenes: Why is it $O(1)$?

To understand the speed, you have to see the **pointers**. A `std::list` node looks like this:

```cpp
struct Node {
    pair<int, int> data; // Key-Value pair
    Node* next;          // Pointer to next
    Node* prev;          // Pointer to previous
};
```

### The Logic of "No Shifting"

In a `std::vector`, if you delete the first element, you have to shift **every other element** to the left. That's $O(N)$.

In a `std::list`, you just change where the neighbors are pointing:

1. `prevNode->next = nextNode;`
2. `nextNode->prev = prevNode;`

**No matter if the list has 10 elements or 10 million, only 2 pointers change.** This is why `push_front`, `push_back`, and `splice` are always $O(1)$.

### Visualizing LRU Splice

When you access an item, we "splice" it to the front.

1. **Unlink**: neighbors point to each other (node is now "free").
2. **Relink**: move pointers so this node becomes the new `head`.

```text
[Head] <-> [Node A] <-> [Node B] <-> [Node C] <-> [Tail]
             (Access B)
[Head] <-> [Node B] <-> [Node A] <-> [Node C] <-> [Tail]
```

The data `[Node B]` never moved in memory; only its `next` and `prev` arrows were updated.

---

## 5. Why LRU needs both `unordered_map` and `list`?

1. **`unordered_map<key, iterator>`**: Gives us $O(1)$ access to find where the item is in the list.
2. **`list<pair<key, value>>`**: Stores the items in order of usage. The most recent is at the `front()`, the least recent at the `back()`.

### The Synergy:

- To access a key:
  1. Find iterator in map ($O(1)$).
  2. Splice node to list front ($O(1)$).
  3. Update map with new front iterator ($O(1)$).

---

## 5. Common Mistakes

- **Trying `l[i]`**: This will not compile. You must use `std::next(l.begin(), i)` or a loop.
- **Relabeling logic**: Forgetting that `erase` on a list returns the next valid iterator.
- **Memory**: Each node has two pointers (prev, next) and the data. It has more memory overhead than a vector.

> [!TIP]
> Always store `pair<key, value>` in the list, not just `value`. When you delete the least recently used item from the `back()` of the list, you need the `key` to delete it from the `unordered_map` too!
