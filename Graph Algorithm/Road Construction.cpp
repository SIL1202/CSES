#include <iostream>
#include <vector>
using namespace std;

class US {
public:
  US(int n) : largest(0), component(n), parent(n + 1), size(n + 1, 1) {
    for (int i = 1; i <= n; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] == x)
      return x;

    return parent[x] = find(parent[x]);
  }

  void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
      return;
    ;

    component--;
    if (size[rootX] < size[rootY])
      swap(rootX, rootY);
    parent[rootY] = rootX;
    size[rootX] += size[rootY];
    largest = max(size[rootX], largest);
  }

  int largest, component;

private:
  vector<int> parent, size;
};

const int MAX = 1e5 + 1;
int main() {
  int n, m;
  cin >> n >> m;

  US uf(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    uf.unite(x, y);
    cout << uf.component << ' ' << uf.largest << '\n';
  }
  return 0;
}
