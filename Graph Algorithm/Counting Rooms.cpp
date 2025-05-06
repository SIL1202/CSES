#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<string> grid;

void bfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push({x, y});
  grid[x][y] = '#'; // 標記為已訪問

  const int dx[] = {1, -1, 0, 0};
  const int dy[] = {0, 0, 1, -1};

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (int d = 0; d < 4; ++d) {
      int ni = i + dx[d], nj = j + dy[d];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '.') {
        grid[ni][nj] = '#';
        q.push({ni, nj});
      }
    }
  }
}

int main() {
  cin >> n >> m;
  grid.resize(n);
  for (auto &row : grid)
    cin >> row;

  int rooms = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (grid[i][j] == '.') {
        bfs(i, j);
        ++rooms;
      }

  cout << rooms << "\n";
  return 0;
}

// This is my own AC version, but isn't clean enough
//
// int main() {
//   int n, m;
//   cin >> n >> m;
//   vector<string> b(n);
//   for (int i = 0; i < n; i++)
//       cin >> b[i];
//
//   int dx[4] = {1, -1, 0, 0};
//   int dy[4] = {0, 0, 1, -1};
//   // vector<vector<bool>> visited(n, vector<bool>(m, false));
//   int count = 0;
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//       if (b[i][j] == '.' /* && !visited[i][j] */) {
//         count++;
//         queue<pair<int, int>> q;
//         q.push({i, j});
//         // visited[i][j] = true;
//
//         while (!q.empty()) {
//           auto [_i, _j] = q.front();
//           q.pop();
//
//           if (_i < 0 || _i >= n || _j < 0 || _j >= m || b[_i][_j] == '#')
//             continue;
//           b[_i][_j] = '#'; // if visited then replace with wall
//
//           for (int d = 0; d < 4; ++d) {
//             int ni = _i + dx[d];
//             int nj = _j + dy[d];
//             if (ni >= 0 && ni < n && nj >= 0 && nj < m && b[ni][nj] == '.')
//               q.push({ni, nj});
//           }
//         }
//       }
//     }
//   }
//   cout << count;
//   return 0;
// }
