#include <stdio.h>
typedef long long ll;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll y, x;
    scanf("%lld %lld", &y, &x);
    ll n = (y > x) ? y : x;
    ll n2 = n * n;
    ll ans;

    if (n % 2 == 0) {
      // even layer: ↓ then ←
      if (y == n)
        ans = n2 - x + 1;
      else
        ans = (n - 1) * (n - 1) + y;
    } else {
      // odd layer: → then ↑
      if (x == n)
        ans = n2 - y + 1;
      else
        ans = (n - 1) * (n - 1) + x;
    }

    printf("%lld\n", ans);
  }
}
