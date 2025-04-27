#include <iostream>
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
