#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  long long a[n];
  for (int i = 0; i < n; i++)
    scanf("%lld", &a[i]);

  long long move = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) {
      long long diff = a[i - 1] - a[i];
      move += diff;
      a[i] = a[i - 1];
    }
  }

  printf("%lld", move);
  return 0;
}
