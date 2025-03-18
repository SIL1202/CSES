#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
int R(int n) {
  if (n == 0)
    return 0;
  if (dp[n] != -1)
    return dp[n];

  int x = n;
  int Min = 1e9;

  while (x != 0) {
    if (x % 10 != 0)
      Min = min(Min, R(n - x % 10) + 1);
    x /= 10;
  }

  return dp[n] = Min;
}

int main() {
  int n;
  cin >> n;
  dp.assign(n + 1, -1);
  cout << R(n);
  return 0;
}

//                              27
//          27 - 2 = 25                  27 - 7 = 20
//  25 - 2 = 23    25 - 5 = 20      20 - 2 = 18     20 - 0 = 20
//
//
//  27 -> 20 -> 18 -> 10 -> 9 -> 0
