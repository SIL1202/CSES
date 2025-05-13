#include <functional>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e5 + 5;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> adj[MAX];
  vector<int> col(n + 1, -1);
  vector<int> team(n + 1, 0);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  function<bool(int, int)> dfs = [&](int v, int c) -> bool {
    col[v] = c;
    for (int node : adj[v]) {
      if (col[node] == -1) {
        if (!dfs(node, c ^ 1))
          return false;

      } else if (col[node] == c)
        return false;
    }
    return true;
  };

  bool res = true;
  for (int i = 1; i <= n; i++) {
    if (col[i] == -1)
      if (!dfs(i, 0)) {
        res = false;
        break;
      }
  }

  if (!res)
    cout << "IMPOSSIBLE\n";
  else
    for (int i = 1; i <= n; i++)
      cout << col[i] + 1 << ' ';

  return 0;
}
