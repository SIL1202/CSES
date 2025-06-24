#include <stdio.h>

typedef long long ll;

int main() {
  int n;
  scanf("%d", &n);
  for (int k = 1; k <= n; ++k) {
    ll total = (ll)k * k;
    ll res = total * (total - 1) / 2;
    if (k > 2) {
      res -= 4 * (k - 1) * (k - 2);
    }
    printf("%lld\n", res);
  }
  return 0;
}
