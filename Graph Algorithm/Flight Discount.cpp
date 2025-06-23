// clang-format off

// 題目目標：找出從城市 1 到城市 n 的最便宜路徑，途中可選一條邊打 5 折（只能使用一次
// 演算法：Dijkstra 最短路徑（使用兩種狀態：未使用 / 已使用折扣） 
// dist[u][0]: 到達 u 時未使用折扣的最短花費 
// dist[u][1]: 到達 u 時已使用折扣的最短花費 
// 時間複雜度：O((n + m) * log n)
#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
const ll INF = 1e18;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pll>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].emplace_back(b, w);
  }

  vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
  // dist[u][0]: reach u but not used
  // dist[u][1]: reach u but used
  priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>>
      pq; // {cost, u, used}

  pq.emplace(0, 1, 0);
  while (!pq.empty()) {
    auto [cost, u, used] = pq.top();
    pq.pop();
    if (cost > dist[u][used])
      continue;
    for (auto [v, w] : adj[u]) {
      if (used == 0) {
        if (dist[v][0] > cost + w) {
          dist[v][0] = cost + w;
          pq.emplace(dist[v][0], v, 0);
        }
        if (dist[v][1] > cost + w / 2) {
          dist[v][1] = cost + w / 2;
          pq.emplace(dist[v][1], v, 1);
        }
      } else {
        if (dist[v][1] > cost + w) {
          dist[v][1] = cost + w;
          pq.emplace(dist[v][1], v, 1);
        }
      }
    }
  }
  cout << dist[n][1] << '\n';
  return 0;
}
