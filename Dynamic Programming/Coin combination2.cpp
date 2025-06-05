#include <iostream>
#include <vector>
using namespace std;
#define mod (int)(1e9 + 7)

// solve 2
void solve2(int a[], int n, int x) {
  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

  // base case: amount 0 can always be formed with no coins
  for (int i = 0; i <= n; ++i)
    dp[i][0] = 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= x; ++j) {
      dp[i][j] = dp[i - 1][j]; // 不使用第 i 個硬幣的情況
      if (j >= a[i - 1])
        dp[i][j] = (dp[i][j] + dp[i][j - a[i - 1]]) % mod;
    }
  }

  cout << dp[n][x];
}

int main() {
  int n, x;
  cin >> n >> x;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  // solve 1
  /*
  vector<int> dp(x + 1, 0);
  dp[0] = 1;

  for (int j = 0; j < n; j++) {
    for (int i = a[j]; i <= x; i++) {
      dp[i] = (dp[i] + dp[i - a[j]]) % mod;
    }
  }
  cout << dp[x];
  */

  solve2(a, n, x);
  return 0;
}
