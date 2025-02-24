#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> events;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    events.push_back({a, 1});
    events.push_back({b, -1});
  }

  sort(events.begin(), events.end(), [](const auto &a, const auto &b) {
    if (a.first == b.first)
      return a.second < b.second;
    return a.first < b.first;
  });

  int customer = 0;
  int max_customer = 0;
  for (auto &event : events) {
    customer += event.second;
    max_customer = max(max_customer, customer);
  }
  cout << max_customer;

  return 0;
}
// _ _ _ _ _ _ _ _ _
//   2   4
//     3           9
//         5     8
