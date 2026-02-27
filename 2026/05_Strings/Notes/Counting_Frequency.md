# Concept Name: String Counting and Frequency Patterns

## 1. Intuition and Core Logic
- **Use Case**: Identifying anagrams, counting character occurrences, or finding unique character distributions.
- **Problem Type**: Anagram grouping, valid anagram checks, or character-limited substrings.

---

## 2. Character Frequency Maps
While `std::unordered_map` is flexible, for strings containing only lowercase English letters, a fixed-size array is faster and uses less memory.

### The `int freq[26]` Pattern
```cpp
int freq[26] = {0};
for (char c : s) {
    freq[c - 'a']++;
}
```
- **Complexity**: $O(|S|)$ time, $O(1)$ space (fixed at 26).

---

## 3. Anagram Logic
Two strings are anagrams if their frequency maps are identical.
- **Preprocessing**: Sorting both strings ($O(N \log N)$) is a quick way to compare, but frequency counting ($O(N)$) is the theoretically optimal method.

---

## 4. Decision Matrix (Read This First)
1. **Comparing character counts?** -> Use a frequency array (size 26) or `unordered_map`.
2. **Need to check anagrams quickly?** -> Sort if $N$ is small, count if $N$ is large.
3. **Problem involves permutations of characters?** -> Think of frequency maps.
4. **Multiple characters set (Unicode)?** -> Use `std::unordered_map`.
