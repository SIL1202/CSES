#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> arr(n);
  vector<ll> prefix(n + 1);
  for (ll &a : arr)
    cin >> a;

  for (int i = 1; i <= n; ++i)
    prefix[i] = prefix[i - 1] + arr[i - 1];

  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    cout << prefix[b] - prefix[a - 1] << '\n';
  }
  return 0;
}

// 1 2 3 4  5  6
//   1 3 6 10 15 21
//
// [a, b] = [2, 5] = 15 - 3
//
