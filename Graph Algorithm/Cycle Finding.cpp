// 題目目標：給定一張有向圖，判斷是否存在「負環」，若有則輸出一組負環的路徑
// 解法：使用 Bellman-Ford 演算法檢查第 n 次鬆弛時是否仍可更新 → 有負環
//   1. 若發現有負環，記住最後被更新的節點 last_updated
//   2. 為保證進入 cycle，從 last_updated 回溯 n 次進入 cycle 內部
//   3. 再從該節點往回走，直到回到自己為止，即為負環路徑
// 輸出任意一個 cycle 中的節點順序（起點與終點相同）
// 時間複雜度：O(n * m)#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

using ll = long long;
const ll INF = 1e18;
using Edge = tuple<int, int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<Edge> edges;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.emplace_back(a, b, c);
  }

  vector<ll> dist(n + 1, 0);
  vector<int> parent(n + 1, -1);
  int last_updated = -1;

  // Bellman-Ford
  for (int i = 0; i < n; i++) {
    last_updated = -1;
    for (auto [u, v, c] : edges) {
      if (dist[u] + c < dist[v]) {
        dist[v] = dist[u] + c;
        parent[v] = u;
        last_updated = v; // 只記一個就夠
      }
    }
  }

  if (last_updated == -1) {
    cout << "NO\n";
  } else {
    // 回溯 n 次保證在 cycle 裡
    int x = last_updated;
    for (int i = 0; i < n; ++i)
      x = parent[x];

    // 建立 cycle
    vector<int> cycle;
    int cur = x;
    do {
      cycle.push_back(cur);
      cur = parent[cur];
    } while (cur != x);
    cycle.push_back(x);
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (int v : cycle)
      cout << v << ' ';
    cout << '\n';
  }
  return 0;
}
