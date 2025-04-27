#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

// 這種找最小子集合的問題不能暴力解
// 記得先排序
// 然後比較相加
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll &a : a)
    cin >> a;

  sort(a.begin(), a.end());
  ll coinSum = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] > coinSum)
      break;
    coinSum += a[i];
  }
  cout << coinSum;
  return 0;
}

// 1 2 2 7 9
// coinSum == 1, 1 <= coinSum
// coinSum = coinSum + 1
//
// coinSum == 2, 2 <= coinSum
// coinSum = coinSum + 2
//
// coinSum == 4, 2 <= coinSum
// coinSum = coinSum + 4
//
// coinSum == 6, 7 > coinSum
// break
