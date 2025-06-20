#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define ll long long
const ll INF = 1e18;
using namespace std;
const int MAX = 1e5;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> adj[n + 1];

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].emplace_back(b, c);
  }

  // {dist, node}
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
  vector<ll> dist(n + 1, INF);
  dist[1] = 0;
  pq.emplace(0, 1);

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u])
      continue;

    for (const auto &[v, w] : adj[u]) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.emplace(dist[v], v);
      }
    }
  }

  for (int i = 1; i <= n; i++)
    cout << dist[i] << ' ';
  return 0;
}
