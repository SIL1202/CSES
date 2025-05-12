#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e5 + 5;
vector<int> adj[MAX];
vector<bool> visited;

void dfs(int node) {
  for (int child : adj[node]) {
    if (!visited[child]) {
      visited[child] = true;
      dfs(child);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  visited.resize(n + 1, false);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> cities;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i);
      cities.push_back(i);
    }
  }

  int N = cities.size() - 1;
  cout << N << '\n';

  if (N)
    for (int i = 1; i < cities.size(); i++)
      cout << cities[i - 1] << ' ' << cities[i] << '\n';

  return 0;
}
