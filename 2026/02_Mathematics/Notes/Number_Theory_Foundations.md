# Concept Name: Number Theory Foundations (GCD, LCM, Primes)

## 1. Intuition and Core Logic
- **Use Case**: Fundamental for problems involving divisibility, distribution, and periodic patterns.
- **Problem Type**: Finding the greatest common divisor, calculating prime factors, or checking primality for a large range of numbers.

---

## 2. Greatest Common Divisor (GCD) and LCM

### Euclidean Algorithm
The most efficient way to find GCD.
- **Logic**: $GCD(a, b) = GCD(b, a \pmod{b})$ until $b = 0$.
- **Complexity**: $O(\log(\min(a, b)))$.

```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

### Least Common Multiple (LCM)
- **Identity**: $a \times b = GCD(a, b) \times LCM(a, b)$.
- **Implementation**: To prevent overflow, always divide first: $LCM(a, b) = (a / GCD(a, b)) \times b$.

---

## 3. Prime Numbers and Sieves

### Sieve of Eratosthenes
The gold standard for precomputing primes up to $N$.
- **Logic**: Mark all numbers as prime. Starting from 2, mark all its multiples as non-prime. Move to the next unmarked number and repeat.
- **Complexity**: $O(N \log(\log N))$.
- **Memory**: $O(N)$.

```cpp
vector<bool> is_prime(N + 1, true);
is_prime[0] = is_prime[1] = false;
for (int p = 2; p * p <= N; p++) {
    if (is_prime[p]) {
        for (int i = p * p; i <= N; i += p)
            is_prime[i] = false;
    }
}
```

### Segmented Sieve
Used when you need primes in a range $[L, R]$ where $R$ is large (up to $10^{12}$) but $R-L$ is small (up to $10^6$).
- **Logic**: Use a regular sieve up to $\sqrt{R}$, then use those primes to mark multiples in the range $[L, R]$.

---

## 4. Prerequisite Map
- **STL Fluency**: Understanding `std::vector` and basic loops.
- **Complexity Analysis**: Understanding logarithmic and linearithmic bounds.

---

## 5. Decision Matrix (Read This First)
1. **Need GCD of two numbers?** -> Use `std::gcd` (C++17) or Euclidean algorithm.
2. **Need all primes up to $10^6$?** -> Use Sieve of Eratosthenes.
3. **Need primality of a single large number?** -> Check divisors up to $\sqrt{N}$.
4. **Range of primes for very large bounds?** -> Use Segmented Sieve.
