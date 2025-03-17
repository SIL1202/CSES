#include <iostream>
using namespace std;
#define mod (int)(1e9 + 7)

// Top-Down
int ways(int n) {
  if (n == 0)
    return 1;

  int result = 0;
  for (int i = 1; i <= 6; i++) {
    if (n < i)
      break;
    result = (result + ways(n - i)) % mod;
  }
  return result;
}

int main() {
  int n;
  cin >> n;
  cout << ways(n);
}

// Bottom-Up
/* int dp[10000001]; // 全域變數初始化為0
int main() {
  // fill(dp, dp + 10000001, 0); // 內顯式設定初始化
  int n;
  cin >> n;
  up[0] = 1; // base case
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      if (j > i)
        break;
      dp[i] = (dp[i] + dp[i - j]) % mod;
    }
  }
  cout << dp[n];
  return 0;
} */

/*

// if only dice 1, 3, 4
dp[0] = 1;
for (int i = 0; i <= n; i++) {
  if (i >= 1)
    dp[i] = (dp[i] + dp[i - 1]) % mod;
  if (i >= 3)
    dp[i] = (dp[i] + dp[i - 3]) % mod;
  if (i >= 4)
    dp[i] = (dp[i] + dp[i - 4]) % mod;
}
*/
