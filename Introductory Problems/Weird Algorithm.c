#include <stdio.h>

int main(void) {
  long long n;
  scanf("%lld", &n);
  while (n != 1) {
    printf("%lld ", n);
    n = (n & 1) ? n * 3 + 1 : n / 2;
  }
  printf("1\n");
  return 0;
}
