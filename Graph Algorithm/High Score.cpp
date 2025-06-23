// Shortest path using Bellman-Ford (with positive cycle detection)
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

using ll = long long;
const ll INF = 1e18;
using Edge = tuple<int, int, ll>; // (u, v, weight)

int main() {
  int n, m;
  cin >> n >> m;
  vector<Edge> edges;
  for (int i = 0; i < m; ++i) {
    int a, b, x;
    cin >> a >> b >> x;
    edges.emplace_back(a, b, -x); // maximize score → minimize negative
  }

  vector<ll> dist(n + 1, INF);
  dist[1] = 0;

  // n-1 rounds of relaxation
  for (int i = 0; i < n - 1; ++i)
    for (auto &[u, v, w] : edges)
      if (dist[u] < INF && dist[v] > dist[u] + w)
        dist[v] = dist[u] + w;

  // n rounds to propagate negative cycle effect
  for (int i = 0; i < n; ++i)
    for (auto &[u, v, w] : edges)
      if (dist[u] < INF && dist[v] > dist[u] + w)
        dist[v] = -INF;

  if (dist[n] == -INF)
    cout << -1 << '\n';
  else
    cout << -dist[n] << '\n'; // revert to positive score
  return 0;
}
