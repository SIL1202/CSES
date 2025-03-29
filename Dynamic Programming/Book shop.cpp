#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> pages(n);
  vector<int> price(n);
  vector<int> dp(x + 1, 0);
  for (int i = 0; i < n; i++)
    cin >> price[i];
  for (int i = 0; i < n; i++)
    cin >> pages[i];

  for (int i = 0; i < n; i++)
    for (int j = x; j >= price[i]; j--) {
      dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
    }

  cout << dp[x] << '\n';
}

/* int main() {
  int n, x;
  cin >> n >> x;

  vector<int> price(n);
  vector<int> pages(n);
  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

  for (int i = 0; i < n; i++)
    cin >> price[i];
  for (int i = 0; i < n; i++)
    cin >> pages[i];

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      int price_ = price[i - 1];
      int page = pages[i - 1];

      int pick = (j >= price_ ? dp[i - 1][j - price_] + page : 0);
      int skip = dp[i - 1][j];

      dp[i][j] = max(pick, skip);
    }
  }
  cout << dp[n][x];
} */
/* int n, x;
vector<int> price;
vector<int> pages;
vector<vector<int>> cache;
int R(int index, int price_) {
  if (price_ > x || index >= n)
    return 0;

  if (cache[index][price_] != -1)
    return cache[index][price_];

  int pick = 0;
  if (price_ + price[index] <= x)
    pick = pages[index] + R(index + 1, price_ + price[index]);
  int skip = R(index + 1, price_);

  return cache[index][price_] = max(pick, skip);
}

int main() {
  cin >> n >> x;
  price.assign(n, 0);
  pages.assign(n, 0);
  cache.assign(n + 1, vector<int>(x + 1, -1));
  for (int i = 0; i < n; i++)
    cin >> price[i];
  for (int i = 0; i < n; i++)
    cin >> pages[i];

  cout << R(0, 0) << endl;
  return 0;
} */
