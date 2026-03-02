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
// Custom implementation (if needed)
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

// C++17 Standard Library (Recommended)
#include <numeric>
long long g = std::gcd(a, b);
long long l = std::lcm(a, b); // Beware: std::lcm can overflow easily if inputs aren't cast to long long!
```

### Least Common Multiple (LCM)
- **Identity**: $a \times b = GCD(a, b) \times LCM(a, b)$.
- **Implementation**: To prevent overflow, always divide first: $LCM(a, b) = (a / GCD(a, b)) \times b$.

### Extended Euclidean Algorithm
Used to find coefficients $x$ and $y$ such that $ax + by = \text{gcd}(a, b)$. Useful for Finding Modular Multiplicative Inverse.
```cpp
long long extgcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
```

---

## 3. Prime Numbers and Sieves

### Sieve of Eratosthenes
The gold standard for precomputing primes up to $N$.
- **Logic**: Mark all numbers as prime. Starting from 2, mark all its multiples as non-prime. Move to the next unmarked number and repeat.
- **Complexity**: $O(N \log\log N)$. Time complexity intuition: the sum of $N/2 + N/3 + N/5 + \dots$ (sum of reciprocals of primes) is bounded by $\log\log N$.
- **Memory**: $O(N)$. Space optimization: use `std::vector<bool>`, which optimizes space by storing 1 bit per boolean.

```cpp
// Generates primes up to N
int N = 1000000;
vector<bool> is_prime(N + 1, true);
is_prime[0] = is_prime[1] = false;
for (int p = 2; p * p <= N; p++) {
    if (is_prime[p]) {
        for (int i = p * p; i <= N; i += p)
            is_prime[i] = false;
    }
}
```

### Smallest Prime Factor (SPF) - $O(\log N)$ Factorization
By precomputing the SPF for every number, we can factorize any number up to $N$ in $O(\log N)$ time. Usually required for multiple queries of factorization.
```cpp
vector<int> spf(N + 1);
for (int i = 2; i <= N; i++) spf[i] = i;

for (int i = 2; i * i <= N; i++) {
    if (spf[i] == i) { // i is prime
        for (int j = i * i; j <= N; j += i) {
            if (spf[j] == j) spf[j] = i;
        }
    }
}

// Factorization step for a specific query
vector<int> factors;
int num = 120;
while (num != 1) {
    factors.push_back(spf[num]);
    num /= spf[num];
}
```

### Segmented Sieve
Used when you need primes in a range $[L, R]$ where $R$ is large (up to $10^{12}$) but $R-L$ is small (up to $10^6$).
- **Logic**: Use a regular sieve up to $\sqrt{R}$, then use those primes to mark multiples in the range $[L, R]$.

```cpp
vector<long long> segmentedSieve(long long L, long long R) {
    long long limit = sqrt(R);
    vector<bool> mark(limit + 1, true);
    vector<long long> primes;
    
    // 1. Regular sieve up to sqrt(R) to collect prime numbers
    for (long long p = 2; p * p <= limit; p++) {
        if (mark[p]) {
            for (long long i = p * p; i <= limit; i += p) mark[i] = false;
        }
    }
    for (long long p = 2; p <= limit; p++) {
        if (mark[p]) primes.push_back(p);
    }
    
    // 2. Sieve the range [L, R]
    vector<bool> isPrime(R - L + 1, true);
    for (long long p : primes) {
        // Find minimum number in [L, R] that is a multiple of p
        long long base = (L / p) * p;
        if (base < L) base += p;
        if (base == p) base += p; // Handle the case where the base is p itself
        
        for (long long i = base; i <= R; i += p) {
            isPrime[i - L] = false; // Mark multiple as not prime
        }
    }
    
    if (L == 1) isPrime[0] = false; // Corner case: 1 is not prime
    
    // 3. Extract the primes
    vector<long long> res;
    for (long long i = 0; i <= R - L; i++) {
        if (isPrime[i]) res.push_back(L + i);
    }
    return res;
}
```

---

## 4. Prerequisite Map
- **STL Fluency**: Understanding `std::vector` and basic loops.
- **Complexity Analysis**: Understanding logarithmic and linearithmic bounds.

---

## 5. Decision Matrix (Read This First)
1. **Need GCD of two numbers?** -> Use `std::gcd` (C++17) or Euclidean algorithm. Ensure `long long` types are used to prevent overflow.
2. **Need all primes up to $10^6$?** -> Use Sieve of Eratosthenes.
3. **Need primality of a single large number?** -> Check divisors up to $\sqrt{N}$.
4. **Range of primes for very large bounds?** -> Use Segmented Sieve.
5. **Need prime factorization for multiple sequence elements?** -> Precompute SPF (Smallest Prime Factor) for $O(\log N)$ point queries.
