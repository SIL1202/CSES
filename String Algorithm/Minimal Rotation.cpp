// using booth algorithm to rotate string by double it first then iterate
#include <iostream>
#include <string>
using namespace std;

int booth(string s) {
  s += s; // double string
  int n = s.length();
  int i = 0, j = 1, k = 0;
  while (i < n / 2 && j < n / 2) {
    k = 0;
    while (k < n / 2 && s[i + k] == s[j + k]) {
      k++;
    }
    if (k == n / 2)
      break;
    if (s[i + k] > s[j + k]) {
      i = max(i + k + 1, j + 1);
    } else {
      j = max(j + k + 1, i + 1);
    }
  }
  return min(i, j);
}

int main() {
  string s;
  cin >> s;
  int pos = booth(s);
  cout << s.substr(pos) + s.substr(0, pos) << '\n';
}
