#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Kadane’s Algorithm
int main() {
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  long long sum = a[0], best = a[0];
  for (int i = 1; i < n; i++) {
    sum = max(a[i], sum + a[i]);
    best = max(sum, best);
  }
  cout << best;
  return 0;
}

// DP
/* int main() {
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<long long> dp(n);
  dp[0] = a[0];
  long long best = dp[0];
  for (int i = 1; i < n; i++) {
    dp[i] = max(a[i], dp[i - 1] + a[i]);
    best = max(best, dp[i]);
  }
  cout << best;
  return 0;
} */
