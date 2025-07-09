#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int p = 31;
const int mod = 1e9 + 9;

// Rabin-Karp: Find all occurrences of pattern in text
vector<int> rabinKarp(const string& text, const string& pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> result;

    // Precompute powers of p
    vector<ll> p_pow(max(n, m));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * p) % mod;

    // Compute prefix hashes of text
    vector<ll> hash(n + 1, 0);
    for (int i = 0; i < n; i++)
        hash[i + 1] = (hash[i] + (text[i] - 'a' + 1) * p_pow[i]) % mod;

    // Hash of pattern
    ll hash_p = 0;
    for (int i = 0; i < m; i++)
        hash_p = (hash_p + (pattern[i] - 'a' + 1) * p_pow[i]) % mod;

    // Compare hashes in all windows of text
    for (int i = 0; i <= n - m; i++) {
        ll cur_hash = (hash[i + m] - hash[i] + mod) % mod;
        if (cur_hash == (hash_p * p_pow[i]) % mod)
            result.push_back(i); // Match at index i
    }

    return result;
}

int main() {
    string text = "ababcabcab";
    string pattern = "abc";

    vector<int> matches = rabinKarp(text, pattern);
    cout << "Pattern found at indices: ";
    for (int idx : matches)
        cout << idx << " ";
    cout << endl;

    return 0;
}
