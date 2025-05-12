#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX = 1e5 + 5;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> adj[MAX];
  vector<bool> visited(n + 1);
  vector<pair<int, int>> parent(n + 1);

  visited.resize(n + 1, false);
  parent.resize(n + 1, {0, 0});

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  auto bfs = [&]() -> bool {
    queue<int> q;
    q.push(1);
    visited[1] = true;
    parent[1] = {0, 1}; // i's parent is -1, and only one element in the route

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      if (node == n)
        return true;

      for (int child : adj[node]) {
        if (!visited[child]) {
          visited[child] = true;
          parent[child] =
              make_pair(node, parent[node].second +
                                  1); // {parentNode, number of computers}
          q.push(child);
        }
      }
    }
    return false;
  };

  if (!bfs())
    cout << "IMPOSSIBLE\n";
  else {
    cout << parent[n].second << '\n';
    vector<int> ans;
    for (int i = n; i > 0; i = parent[i].first)
      ans.push_back(i);

    reverse(ans.begin(), ans.end());
    for (int a : ans)
      cout << a << ' ';
  }

  return 0;
}
