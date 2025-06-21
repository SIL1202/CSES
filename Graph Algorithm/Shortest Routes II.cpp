#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
#define ll long long
const ll INF = 1e18;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].emplace_back(b, w);
    adj[b].emplace_back(a, w);
  }

  vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
  for (int i = 1; i <= n; i++)
    dist[i][i] = 0;

  for (int u = 1; u <= n; u++)
    for (const auto &[v, w] : adj[u])
      dist[u][v] = min(dist[u][v], (ll)w);

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    cout << (dist[a][b] == INF ? -1 : dist[a][b]) << '\n';
  }
  return 0;
}
