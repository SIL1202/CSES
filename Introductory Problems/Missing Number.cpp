#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<bool> arr(n + 1, false);
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    arr[x] = true;
  }

  for (int i = 1; i <= n; ++i) {
    if (!arr[i])
      cout << i;
  }
  return 0;
}

// 1 2 3 5
//       i
