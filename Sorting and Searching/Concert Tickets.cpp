#include <iostream>
#include <set>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  multiset<int> tickets;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    tickets.insert(t);
  }

  for (int i = 0; i < m; i++) {
    int budget;
    cin >> budget;

    auto it = tickets.upper_bound(budget);
    if (it == tickets.begin())
      cout << "-1\n";
    else {
      --it;
      cout << *it << endl;
      tickets.erase(it);
    }
  }
  return 0;
}

// 5 3 7 8 5
// i
// 4 8 3
// j
