#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  // initializing the dp values with a very high value
  vector<int> dp(x + 1, 1e9);

  // base case
  dp[0] = 0;
  for (int i = 1; i <= x; i++) {  // O(x)
    for (int j = 0; j < n; j++) { // O(n)
      if (a[j] <= i) {
        // transition
        dp[i] = min(dp[i], dp[i - a[j]] + 1);
      }
    }
  }

  // final subproblem
  cout << (dp[x] < 1e9 ? dp[x] : -1);
  return 0;
}
