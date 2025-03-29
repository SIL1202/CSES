#include <iostream>
#include <vector>
using namespace std;

#define mod (int)(1e9 + 7)

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  // dp[i][k] = number of ways to build a prefix of size i,
  // such that the last element of the prefix is k.
  //
  // Base case
  for (int i = 1; i <= m; i++)
    if (a[0] == 0 || a[0] == i)
      dp[1][i] = 1;

  for (int i = 2; i <= n; i++) {
    for (int k = 1; k <= m; k++) {
      // find dp[i][k] here
      if (a[i - 1] != 0 && a[i - 1] != k) {
        dp[i][k] = 0;
        continue;
      }

      for (int prev = k - 1; prev <= k + 1; prev++) {
        if (prev < 1 || prev > m)
          continue;
        // transition
        dp[i][k] = (dp[i][k] + dp[i - 1][prev]) % mod;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; i++)
    ans = (ans + dp[n][i]) % mod;

  cout << ans;
  return 0;
}
