# Greedy Algorithms Cheatsheet — Summary & Usage Guide

---

## 1. Activity Selection

**Meaning:**  
Pick the maximum number of non-overlapping activities from given start and end times.

**Summary:**  
Sort by finishing time, greedily choose activities that finish earliest.

**When to use:**  
When you need to schedule the maximum tasks/events without overlap, like meeting room scheduling, lecture halls, etc.

---

## 2. Huffman Encoding

**Meaning:**  
Generate variable-length prefix codes to compress data optimally based on frequency.

**Summary:**  
Build a binary tree by repeatedly merging the two least frequent symbols, assign codes by tree traversal.

**When to use:**  
For lossless data compression where shorter codes are assigned to frequent symbols, e.g., file compression, text encoding.

---

## 3. Job Scheduling with Deadlines and Profits

**Meaning:**  
Schedule jobs with deadlines to maximize total profit; each job takes one unit of time.

**Summary:**  
Sort jobs by profit descending, assign jobs to latest free slot before deadline.

**When to use:**  
When you must maximize profit or value from tasks with deadlines, like CPU scheduling, project management with priority tasks.

---

## 4. Interval Scheduling / Merging Intervals

**Meaning:**  
Combine overlapping intervals into merged intervals representing consolidated time spans.

**Summary:**  
Sort intervals by start time, merge if current interval overlaps with previous.

**When to use:**  
When dealing with ranges/time slots where overlaps need to be combined, e.g., calendar event merging, resource allocation.

---

# Quick Selection Guide

| Problem                     | Key Idea                         | Usage Scenario                              |
|-----------------------------|---------------------------------|---------------------------------------------|
| Activity Selection           | Earliest finish time first       | Max non-overlapping tasks                     |
| Huffman Encoding            | Merge lowest frequency nodes     | Optimal prefix-free encoding/compression     |
| Job Scheduling              | Highest profit first              | Maximize profit with deadlines                |
| Interval Merging            | Merge overlapping intervals      | Consolidate overlapping ranges/time slots    |

---