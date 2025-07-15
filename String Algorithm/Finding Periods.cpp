// using z algorithm to solve find the periods of the prefix
#include <iostream>
#include <sys/resource.h>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (i <= r)
      z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] <= n && s[z[i]] == s[i + z[i]])
      ++z[i];
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  for (int i = 1; i < n; ++i)
    if (i + z[i] == n)
      cout << i << ' ';
  cout << n << '\n';
  return 0;
}
