#include <iostream>
#include <utility>
using namespace std;
const int MAX = 1e5;
int n, m;
vector<pair<int, int>> adj[MAX];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  return 0;
}
