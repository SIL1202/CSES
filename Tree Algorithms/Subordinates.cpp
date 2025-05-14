#include <functional>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2e5 + 5;
int main() {
  int n;
  cin >> n;
  vector<int> adj[MAX];
  for (int i = 2; i <= n; i++) {
    int a;
    cin >> a;
    adj[a].push_back(i);
  }

  vector<int> sub(n + 1);
  function<int(int)> dfs = [&](int v) -> int {
    int total = 0;
    for (int u : adj[v]) {
      total += 1 + dfs(u);
    }
    sub[v] = total;
    return total;
  };

  dfs(1);

  for (int i = 1; i <= n; i++) {
    cout << sub[i] << ' ';
  }
  return 0;
}
