# Concept Name: String Two-Pointer Patterns (Palindromes)

## 1. Intuition and Core Logic
- **Use Case**: Efficiently checking symmetry or modifying strings in-place.
- **Problem Type**: Palindrome validation, longest palindromic substring, or reversing words.

---

## 2. Palindrome Patterns

### Symmetric Check (Outside-In)
- **Logic**: Use `left = 0` and `right = N-1`. Move inward and compare.
- **Complexity**: $O(N)$.

### Palindrome Expansion (Inside-Out)
- **Logic**: For each center (character or gap), expand outward as long as characters match.
- **Use Case**: Finding the longest palindromic substring.
- **Complexity**: $O(N^2)$.

---

## 3. String Manipulation with Two Pointers
- **Reversal**: Swap `s[left]` and `s[right]` while moving inward.
- **Filtering**: Move one pointer to search for a character (e.g., a vowel) and another to find its swap partner.

---

## 4. Decision Matrix (Read This First)
1. **Need to check if a string is a palindrome?** -> Use Outside-In two pointers.
2. **Finding the largest palindrome in a string?** -> Use Inside-Out expansion.
3. **Reversing specific characters only?** -> Use two pointers with a `while` loop to skip non-targets.
4. **Comparing two strings with special rules?** -> Use one pointer for each string.
