#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e5 + 5;
int n, m;
vector<int> adj[MAX];
vector<int> parent;
vector<bool> visited;
int cir_start = -1, cir_end = -1;

bool dfs(int node, int par) {
  visited[node] = true;
  parent[node] = par; // 如果放在迴圈裡面會被重設parent

  for (int child : adj[node]) {
    if (visited[child] && child != par) {
      cir_start = child; // 走到 child 形成環所以 child 為 start
      cir_end = node;    // node 為 end
      return true;
    }

    if (!visited[child])
      if (dfs(child, node))
        return true;
  }

  return false;
}

int main() {
  cin >> n >> m;
  visited.resize(n + 1, false);
  parent.resize(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  // graph may not be connected graph, so it need to iterate through all nodes
  for (int i = 1; i <= n; i++) {
    if (!visited[i] && dfs(i, -1))
      break;
  }

  if (cir_start == -1)
    cout << "IMPOSSIBLE\n";
  else {
    vector<int> vec;
    vec.push_back(cir_start); // store the first vertex
    for (int i = cir_end; i != cir_start; i = parent[i]) {
      vec.push_back(i);
    }
    vec.push_back(cir_start); // store the first vertex again

    cout << vec.size() << '\n';
    for (int v : vec)
      cout << v << ' ';
    cout << '\n';
  }
  return 0;
}
