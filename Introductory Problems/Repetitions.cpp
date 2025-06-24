#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int M = 0;
  int c = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1])
      c++;
    else {
      M = max(M, c);
      c = 1;
    }
  }

  cout << max(M, c) << '\n';
}
