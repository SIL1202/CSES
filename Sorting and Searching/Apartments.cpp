#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> appliant(n);
  vector<int> apartment(m);
  for (int i = 0; i < n; i++)
    cin >> appliant[i];

  for (int i = 0; i < m; i++)
    cin >> apartment[i];

  sort(appliant.begin(), appliant.end());
  sort(apartment.begin(), apartment.end());
  int count = 0;
  int i, j;
  i = j = 0;

  while (i < n && j < m) {
    if (abs(appliant[i] - apartment[j]) <= k) {
      i++;
      j++;
      count++;
    } else if (appliant[i] > apartment[j])
      j++;
    else
      i++;
  }
  cout << count;

  return 0;
}
