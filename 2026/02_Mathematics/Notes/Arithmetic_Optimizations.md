# Concept Name: Arithmetic Optimizations (Modular, Fast Power)

## 1. Intuition and Core Logic
- **Use Case**: Handling very large numbers and repeated multiplications efficiently without overflow.
- **Problem Type**: Combinatorics, probability, or calculating large powers under a modulo (usually $10^9 + 7$).

---

## 2. Modular Arithmetic Rules
Essential for avoiding overflow.
1. $(a + b) \pmod{M} = ((a \pmod{M}) + (b \pmod{M})) \pmod{M}$
2. $(a - b) \pmod{M} = ((a \pmod{M}) - (b \pmod{M}) + M) \pmod{M}$
3. $(a \times b) \pmod{M} = ((a \pmod{M}) \times (b \pmod{M})) \pmod{M}$
4. $(a / b) \pmod{M} = (a \times b^{-1}) \pmod{M}$ (Requires Modular Multiplicative Inverse).

---

## 3. Binary Exponentiation (Fast Power)
Calculate $a^b \pmod{M}$ in logarithmic time.
- **Logic**: Divide and Conquer. $a^{10} = (a^5)^2$. This is a specific instance of "Binary Lifting" logic.
- **Complexity**: $O(\log B)$.

```cpp
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
```

---

## 4. Overflow Protection
- **Rule of Thumb**: Intermediate results must fit in the data type. 
- **Pattern**: If $a$ and $b$ are $10^9$, their product is $10^{18}$, which fits in `long long` but not `int`.
- **Safe Multiplication**: When multiplying $a, b \pmod{M}$ where $M$ is up to $10^{18}$, use `__int128` or binary multiplication (similar to `binpow`).

---

## 5. Decision Matrix (Read This First)
1. **Handling Subtraction Modulo?** -> Always add $M$ before the final modulo to avoid negative results.
2. **Calculating $a^b$?** -> Always use Binary Exponentiation if $b > 3$.
3. **Problem asks for "Answer modulo $10^9+7$"?** -> Apply modulo at EVERY step of multiplication and addition.
