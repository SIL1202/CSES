#include <iostream>
#include <vector>
#define mod (int)(1e9 + 7)
using namespace std;

// Top-Down
/*
long long R(vector<vector<char>> &grid, int i, int j) {
  if (i < 0 || j < 0)
    return 0;
  if (grid[i][j] == '*')
    return 0;
  if (i == 0 && j == 0)
    return 1;

  if (dp[i][j] == -1)
    dp[i][j] = R(grid, i - 1, j) + R(grid, i, j - 1);
  return dp[i][j];
}
*/

int main() {
  int n;
  cin >> n;
  vector<vector<int>> dp(n, vector<int>(n, 0));
  vector<vector<char>> grid(n, vector<char>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> grid[i][j];

  if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*')
    cout << 0;
  else {
    dp[0][0] = 1;

    for (int i = 1; i < n; i++) {
      if (grid[i][0] == '*')
        break;
      dp[i][0] = dp[i - 1][0];
    }

    for (int j = 1; j < n; j++) {
      if (grid[0][j] == '*')
        break;
      dp[0][j] = dp[0][j - 1];
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < n; j++) {
        if (grid[i][j] == '.') {
          dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
      }
    }
    cout << dp[n - 1][n - 1] % mod;
  }
  return 0;
}
