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
- **Left Shift (`<<`)**: Multiply by $2^n$.
- **Right Shift (`>>`)**: Divide by $2^n$.

---

## 3. XOR Properties (The Magic of XOR)
1. $x \oplus x = 0$
2. $x \oplus 0 = x$
3. $x \oplus y = y \oplus x$ (Commutative)
4. $(x \oplus y) \oplus z = x \oplus (y \oplus z)$ (Associative)

### Common Pattern: The Unique Element
If every number in an array appears twice except one, XORing all elements together results in the unique number.

---

## 4. Useful Bit Tricks
- **Check if Power of 2**: `(x & (x - 1) == 0)` (Works for $x > 0$).
- **Count Set Bits (Popcount)**: `__builtin_popcount(x)` (GCC specific).
- **Extract Rightmost Set Bit**: `(x & -x)`.
- **Toggle $i$-th Bit**: `x ^ (1 << i)`.
- **Check if $i$-th Bit is Set**: `(x >> i) & 1`.

---

## 5. Decision Matrix (Read This First)
1. **Need to check if $x$ is even/odd?** -> Use `(x & 1)`.
2. **Need to find a number that appears once?** -> Use XOR.
3. **Problem involves subsets?** -> Think of bitmasks (each bit represents an element).
4. **Need to multiply/divide by powers of 2?** -> Use shifts for speed.
