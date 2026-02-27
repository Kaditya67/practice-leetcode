# Concept Name: Linked List Transformation Patterns (Reversal, Merge)

## 1. Intuition and Core Logic
- **Use Case**: Rearranging node connections to solve structural problems without creating new nodes.
- **Problem Type**: Reversing a list (or part of it), merging sorted lists, or reordering nodes (e.g., Odd-Even or K-group).

---

## 2. In-place List Reversal
The most foundational transformation.
- **Logic**: Use three pointers (`prev`, `curr`, `next`) to flip the direction of each `next` pointer.

```cpp
ListNode *prev = NULL, *curr = head;
while (curr) {
    ListNode* nextNode = curr->next; // Store next
    curr->next = prev; // Flip pointer
    prev = curr; // Move prev
    curr = nextNode; // Move curr
}
return prev; // New head
```

---

## 3. Merging Sorted Lists
- **Logic**: Compare heads of two lists and attach the smaller node to your `curr` pointer. Move the head of the chosen list.
- **Use Case**: Merge Sort on Linked Lists or merging $K$ sorted lists.

---

## 4. K-Group Transformations
- **Logic**: Divide the list into segments of size $K$ and reverse each segment individually. Connect the tail of the previous segment to the head of the current reversed segment.

---

## 5. Decision Matrix (Read This First)
1. **Need to reverse the whole list?** -> Use the standard 3-pointer reversal.
2. **Merging lists?** -> Use a Dummy node and a `while` loop.
3. **Complex rewiring (Odd-Even, Palindrome)?** -> Break the problem into "Find middle -> Reverse second half -> Merge/Compare."
4. **Safety Check**: Always check for `NULL` before accessing `curr->next`.
