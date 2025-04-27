#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
  int n;
  ll x;
  cin >> n >> x;
  vector<pair<ll, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }

  sort(a.begin(), a.end());

  int l = 0, r = n - 1;
  while (l < r) {
    ll sum = a[l].first + a[r].first;
    if (sum == x) {
      cout << a[l].second << " " << a[r].second;
      return 0;
    }
    if (sum < x)
      l++;
    else
      r--;
  }
  cout << "IMPOSSIBLE";
}
