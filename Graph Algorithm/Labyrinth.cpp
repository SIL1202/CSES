#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<pair<int, int>>> from;
int dx[4] = {1, -1, 0, 0}; // D, U, R, L
int dy[4] = {0, 0, 1, -1};
char C[4] = {'D', 'U', 'R', 'L'};

int ex, ey; // 終點位置（在 BFS 中更新）

bool bfs(int sx, int sy) {
  queue<pair<int, int>> q;
  q.push({sx, sy});
  grid[sx][sy] = '#'; // 起點標記為已走過

  while (!q.empty()) {
    auto prev = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int x = prev.first + dx[i];
      int y = prev.second + dy[i];
      if (x < 0 || x >= n || y < 0 || y >= m)
        continue;
      if (grid[x][y] == '#')
        continue;

      from[x][y] = prev;

      if (grid[x][y] == 'B') {
        ex = x;
        ey = y;
        return true;
      }

      grid[x][y] = '#'; // 標記已拜訪
      q.push({x, y});
    }
  }
  return false;
}

string reconstruct(int sx, int sy) {
  string path;
  int x = ex, y = ey;

  while (make_pair(x, y) != make_pair(sx, sy)) {
    auto p = from[x][y];
    for (int i = 0; i < 4; i++) {
      if (p.first + dx[i] == x && p.second + dy[i] == y) {
        path += C[i];
        break;
      }
    }
    x = p.first;
    y = p.second;
  }

  reverse(path.begin(), path.end());
  return path;
}

int main() {
  cin >> n >> m;
  grid.resize(n);
  from.assign(n, vector<pair<int, int>>(m));

  int sx, sy;
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'A') {
        sx = i;
        sy = j;
      }
    }
  }

  if (!bfs(sx, sy)) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    string ans = reconstruct(sx, sy);
    cout << ans.size() << endl;
    cout << ans << endl;
  }

  return 0;
}
