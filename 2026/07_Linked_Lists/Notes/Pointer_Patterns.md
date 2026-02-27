# Concept Name: Linked List Pointer Patterns (Fast/Slow, Dummy Nodes)

## 1. Intuition and Core Logic
- **Use Case**: Navigating and restructuring non-contiguous memory structures efficiently.
- **Problem Type**: Middle of the list, cycle detection, or merging two lists without losing the head.
- **The Core Pattern**: Using multiple pointers moving at different speeds or starting with a "placeholder" node to simplify edge cases.

---

## 2. Fast and Slow Pointers (Two Pointers)

### Finding the Middle
- **Logic**: Move `fast` by 2 steps and `slow` by 1 step. When `fast` reaches the end, `slow` is at the middle.

### Cycle Detection (Floyd’s Algorithm)
- **Logic**: If a cycle exists, `fast` will eventually "lap" `slow` and they will meet at the same node.
- **Complexity**: $O(N)$ time, $O(1)$ space.

---

## 3. Dummy Node Technique
- **Logic**: Create a temporary `dummy` node whose `next` points to the head of your list.
- **Use Case**: Eliminates special code for handling empty lists or cases where the head of the list changes (e.g., merging, deleting the first node).

```cpp
ListNode* dummy = new ListNode(0);
dummy->next = head;
ListNode* prev = dummy;
// ... process list ...
return dummy->next;
```

---

## 4. Decision Matrix (Read This First)
1. **Need the middle of the list?** -> Use Fast/Slow pointers.
2. **Checking for a loop?** -> Use Floyd’s Cycle Detection.
3. **Head of the list might change?** -> Always start with a Dummy Node.
4. **Need the K-th node from the end?** -> Move `fast` $K$ steps ahead, then move `fast` and `slow` together.
5. **Finding intersection?** -> Use two pointers; when one hits NULL, restart it at the other head.
 Jonah
