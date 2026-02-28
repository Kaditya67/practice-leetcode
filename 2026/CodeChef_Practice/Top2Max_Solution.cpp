#include <algorithm>
#include <iostream>
#include <set>
#include <vector>


using namespace std;

/**
 * Problem: Top 2 Max (CodeChef)
 * Logic: DP on Cartesian Tree visibility pairs.
 * Complexity: O(T * N^2 * N^3) = O(T * N^5)
 */

long long MOD = 998244353;

int N;
int f[17][17];
long long dp[17][17]; // dp[len][max_val]

long long solve_for_v(int v) {
  // Reset DP
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      dp[i][j] = 0;
    }
  }

  dp[0][0] = 1; // Base case: empty array

  for (int len = 1; len <= N; len++) {
    for (int m = 1; m <= N; m++) {
      // First occurrence of m at index k (0 to len-1)
      for (int k = 0; k < len; k++) {
        long long left_sum = 0;
        // m_L < m
        for (int ml = 0; ml < m; ml++) {
          if (ml == 0 || f[m][ml] <= v) {
            left_sum = (left_sum + dp[k][ml]) % MOD;
          }
        }

        long long right_sum = 0;
        // m_R <= m
        for (int mr = 0; mr <= m; mr++) {
          if (mr == 0 || f[m][mr] <= v) {
            right_sum = (right_sum + dp[len - 1 - k][mr]) % MOD;
          }
        }

        dp[len][m] = (dp[len][m] + (left_sum * right_sum) % MOD) % MOD;
      }
    }
  }

  long long total = 0;
  for (int m = 1; m <= N; m++) {
    total = (total + dp[N][m]) % MOD;
  }
  return total;
}

void solve() {
  if (!(cin >> N))
    return;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> f[i][j];
    }
  }

  set<int> distinct_f;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      distinct_f.insert(f[i][j]);
    }
  }

  vector<int> values(distinct_f.begin(), distinct_f.end());
  vector<long long> counts;

  // W(v) = count arrays with max score <= v
  for (int v : values) {
    counts.push_back(solve_for_v(v));
  }

  long long ans = 0;
  long long prev_count = 0;
  for (int i = 0; i < values.size(); i++) {
    long long current_v_count = (counts[i] - prev_count + MOD) % MOD;
    ans = (ans + (long long)values[i] * current_v_count) % MOD;
    prev_count = counts[i];
  }

  cout << ans << endl;
}

int main() {
  int T;
  if (!(cin >> T))
    return 0;
  while (T--) {
    solve();
  }
  return 0;
}
