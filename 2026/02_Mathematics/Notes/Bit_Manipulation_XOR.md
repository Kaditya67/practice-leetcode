# Concept Name: Bit Manipulation & XOR Patterns

## 1. Intuition and Core Logic
- **Use Case**: Low-level optimization and solving problems involving subsets, uniqueness, or mathematical properties of binary representations.
- **Problem Type**: Checking if a number is a power of 2, counting set bits, or finding the single unique element in an array of pairs.

---

## 2. Basic Bitwise Operators
- **AND (`&`)**: Both bits must be 1. (Used for masking/extracting).
- **OR (`|`)**: At least one bit must be 1. (Used for setting bits).
- **XOR (`^`)**: Bits must be different. (Used for toggling/uniqueness).
- **NOT (`~`)**: Flips all bits.
- **Left Shift (`<<`)**: Multiply by $2^n$. (Be careful with overflow: `1LL << n`).
- **Right Shift (`>>`)**: Divide by $2^n$.

---

## 3. XOR Properties (The Magic of XOR)
1. $x \oplus x = 0$ (Self-inverse)
2. $x \oplus 0 = x$ (Identity)
3. $x \oplus y = y \oplus x$ (Commutative)
4. $(x \oplus y) \oplus z = x \oplus (y \oplus z)$ (Associative)

### Common Pattern: Single Number Series
1. **Single Number I**: Every element appears exactly twice except one.
   - **Solution**: XOR all elements. The remaining value is the unique one.
2. **Single Number II**: Every element appears exactly three times except one.
   - **Solution**: Keep track of bit counts modulo 3. Or use logic gates simulation (`ones = (ones ^ x) & ~twos`).
3. **Single Number III**: Every element appears exactly twice except two elements.
   - **Solution**: XOR all elements to get `a ^ b`. Find any set bit in `a ^ b` (e.g., rightmost set bit using `diff &= -diff`). Group numbers by whether they have this bit set or not, then XOR each group independently to find `a` and `b`.

---

## 4. Useful Bit Tricks
- **Extract Rightmost Set Bit**: `x & -x`. Isolate the lowest bit that is 1. (Very useful in Fenwick Trees).
- **Clear Rightmost Set Bit (Brian Kernighan's Alg)**: `x & (x - 1)`. Drops the lowest set bit.
- **Check if Power of 2**: `(x & (x - 1)) == 0` (Make sure $x > 0$).
- **Toggle $i$-th Bit**: `x ^ (1LL << i)`.
- **Set $i$-th Bit**: `x | (1LL << i)`.
- **Clear $i$-th Bit**: `x & ~(1LL << i)`.
- **Check if $i$-th Bit is Set**: `(x >> i) & 1` or `(x & (1LL << i)) != 0`.

---

## 5. Built-in Functions (GCC Specific, O(1) time)
- **Count Set Bits (Popcount)**: `__builtin_popcount(x)` for `int` and `__builtin_popcountll(x)` for `long long`.
- **Count Leading Zeros**: `__builtin_clz(x)` for `int`, `__builtin_clzll(x)` for `long long`. Number of 0s before the most significant 1 bit.
- **Count Trailing Zeros**: `__builtin_ctz(x)` for `int`, `__builtin_ctzll(x)` for `long long`. Number of 0s after the least significant 1 bit.

---

## 6. Iterating Over Submasks
Given a bitmask `mask`, you can iterate over all its non-empty submasks efficiently in $O(3^N)$ across all subsets instead of $O(4^N)$.
```cpp
for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
    // submask is a valid submask of mask
}
```

---

## 7. Decision Matrix (Read This First)
1. **Need to check if $x$ is even/odd?** -> Use `(x & 1)`.
2. **Need to find a number that appears once?** -> Use XOR.
3. **Problem involves subsets?** -> Think of bitmasks (each bit represents an element constraint).
4. **Need to iterate over valid subsets of a subset?** -> Use the `(submask - 1) & mask` trick.
5. **Need to multiply/divide by powers of 2?** -> Use shifts (`<<` / `>>`) for speed.
6. **Counting bits?** -> Never loop 32 times if you can use `__builtin_popcount`.
