# Concept Name: Arithmetic Optimizations (Modular, Fast Power)

## 1. Intuition and Core Logic
- **Use Case**: Handling very large numbers and repeated multiplications efficiently without overflow.
- **Problem Type**: Combinatorics, probability, or calculating large powers under a modulo (usually $10^9 + 7$).

---

## 2. Modular Arithmetic Rules
Essential for avoiding overflow.
1. **Addition**: $(a + b) \pmod{M} = ((a \pmod{M}) + (b \pmod{M})) \pmod{M}$
2. **Subtraction**: $(a - b) \pmod{M} = ((a \pmod{M}) - (b \pmod{M}) + M) \pmod{M}$ (The `+ M` is crucial to handle negative results in C++)
3. **Multiplication**: $(a \times b) \pmod{M} = ((a \pmod{M}) \times (b \pmod{M})) \pmod{M}$
4. **Division**: $(a / b) \pmod{M} = (a \times b^{-1}) \pmod{M}$ (Requires Modular Multiplicative Inverse).

### Modular Multiplicative Inverse
By Fermat's Little Theorem, if $M$ is prime, then $b^{M-1} \equiv 1 \pmod{M}$, which means $b^{-1} \equiv b^{M-2} \pmod{M}$.
```cpp
// Returns b^-1 mod M
// Requires M to be prime. Uses binpow (defined below)
long long modInverse(long long b, long long M) {
    return binpow(b, M - 2, M);
}
```

---

## 3. Binary Exponentiation (Fast Power)
Calculate $a^b \pmod{M}$ in logarithmic time $O(\log B)$.
- **Logic**: Divide and Conquer. $a^{10} = (a^5)^2$. This is a specific instance of "Binary Lifting" logic.

```cpp
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % m; // If b is odd, multiply a with result
        a = (a * a) % m; // Square the base
        b >>= 1; // Divide b by 2
    }
    return res;
}
```

---

## 4. Overflow Protection
- **Rule of Thumb**: Intermediate results must fit in the data type. 
- **Pattern**: If $a$ and $b$ are $10^9$, their product is $10^{18}$, which fits in `long long` but not `int`.
- **Extreme Case**: What if $M = 10^{18}$? Then $a \times b$ can be $10^{36}$, which overflows `long long`!

### Method 1: Iterative Addition (Binary Multiplication)
Similar to binary exponentiation, but uses addition instead of multiplication.
- **Complexity**: $O(\log B)$.
```cpp
long long binmul(long long a, long long b, long long m) {
    long long res = 0;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}
```

### Method 2: using `__int128` (GCC Specific, much faster)
- **Complexity**: $O(1)$.
```cpp
long long fastmul(long long a, long long b, long long m) {
    return (long long)((__int128)a * b % m);
}
```

---

## 5. Decision Matrix (Read This First)
1. **Handling Subtraction Modulo?** -> Always add $M$ before the final modulo to avoid negative results: `(a - b) % M = (a % M - b % M + M) % M`.
2. **Calculating $a^b$?** -> Always use Binary Exponentiation (`binpow`) if $b > 3$.
3. **Calculating $(a / b) \pmod{M}$?** -> Find modular multiplicative inverse of $b$ and multiply it by $a$: `(a * modInverse(b, M)) % M`.
4. **Problem asks for "Answer modulo $10^9+7$"?** -> Apply modulo at EVERY single step of multiplication and addition.
5. **Modulus $M \approx 10^{18}$ and multiplying?** -> Use `__int128` casting or `binmul` to prevent $10^{36}$ overflow.
