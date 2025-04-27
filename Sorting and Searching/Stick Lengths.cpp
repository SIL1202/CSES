#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
#define ll long long

// 數字：1, 2, 1000
// 如果取平均數：
/* 	•	平均 = (1+2+1000)/3 = 334.333…
    •	大家調成 334 ？
    •	那麼 1 要調成 334，成本是 333，超大。
    •	2 要調成 334，成本是 332。
    •	1000 要調成 334，成本是 666。
    •	總花費：333+332+666=1331

超級爆炸！
⸻
如果取中位數：
    •	中位數是 2。
    •	把所有數調成 2：
    •	1 → 2，成本 1
    •	2 → 2，成本 0
    •	1000 → 2，成本 998
    •	總花費：1+0+998=999

是不是小超多？！
 */
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);

  for (ll &A : a)
    cin >> A;

  sort(a.begin(), a.end());
  ll median = a[n / 2];
  ll cost = 0;
  for (ll &A : a) {
    cost += abs(A - median);
  }
  cout << cost;
  return 0;
}
