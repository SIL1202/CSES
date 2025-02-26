#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> movies(n);
  for (int i = 0; i < n; i++) {
    cin >> movies[i].first >> movies[i].second;
  }
  sort(movies.begin(), movies.end(),
       [](const auto &a, const auto &b) { return a.second < b.second; });
  int count = 0;
  int current_end = -1;
  for (auto &movie : movies) {
    int start = movie.first;
    int end = movie.second;

    if (start >= current_end) {
      count++;
      current_end = end;
    }
  }
  cout << count;
  return 0;
}
