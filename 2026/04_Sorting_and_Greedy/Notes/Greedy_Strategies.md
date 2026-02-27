# Concept Name: Greedy Strategies (Intervals, Local/Global)

## 1. Intuition and Core Logic
- **Use Case**: Making the best local choice at each step to reach a global optimum.
- **Problem Type**: Interval scheduling, minimum platform problems, or Huffman coding.
- **The Challenge**: Greedy is "Easy to code, hard to prove." If you can't prove it, you might get a hidden WA.

---

## 2. Interval Problems
One of the most common applications of Greedy.

### Interval Selection (Max Disjoint Intervals)
- **Logic**: Always pick the interval that **ends earliest**. This leaves the maximum room for subsequent intervals.
- **Sort Key**: End Time.

### Interval Merging
- **Logic**: Sort intervals and merge if they overlap.
- **Sort Key**: Start Time.

---

## 3. Local vs. Global Optimum
A greedy choice is valid only if making the "locally best" choice never prevents you from reaching the "globally best" result.

### Counterexample Testing
Before committing to a greedy strategy:
1.  Try to think of a case where the greedy choice is wrong.
2.  If you can't find one, the strategy might be valid.
3.  Common pitfalls: Sorting by the wrong attribute (e.g., Duration instead of End Time).

---

## 4. Decision Matrix (Read This First)
1. **Overlap problems?** -> Sort by Start/End time and process greedily.
2. **Optimization problem with many choices?** -> Check if a greedy property exists.
3. **Unsure if greedy works?** -> Try a small manual example. If it fails, move to Dynamic Programming.
4. **Tie-breaking matters?** -> Be explicit in your comparator.
