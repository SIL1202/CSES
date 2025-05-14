#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

#define pb push_back
const int MAX = 2e5 + 5;
int main() {
  int n;
  cin >> n;
  vector<int> adj[MAX];
  vector<int> vis(n + 1, false);
  int a, b;
  for (int i = 0; i < n - 1; i++)
    cin >> a >> b, adj[a].pb(b), adj[b].pb(a);

  int maxD, maxNode;
  function<void(int, int)> dfs = [&](int v, int d) -> void {
    vis[v] = true;
    if (d > maxD)
      maxD = d, maxNode = v;

    for (int u : adj[v]) {
      if (!vis[u]) {
        dfs(u, d + 1);
      }
    }
  };

  maxD = -1;
  dfs(1, 0);

  vis.assign(n + 1, false);
  maxD = -1;
  dfs(maxNode, 0);
  cout << maxD << '\n';
}
