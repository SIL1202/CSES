#include <iostream>
#include <vector>
using namespace std;
#define ll long long

// =============================
// Knuth-Morris-Pratt algorithm complete version
// =============================
vector<int> LPS(string p) {
  int m = p.length();
  vector<int> lps(m);
  int i, j;
  i = 1, j = 0;
  while (i < m) {
    if (p[i] == p[j])
      lps[i++] = ++j;
    else {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}

// ababcabab
// bababababcababcabab
int KMP(string s, string p) {
  int n = s.length();
  int m = p.length();
  int count = 0;
  vector<int> lps = LPS(p);
  int i, j;
  i = j = 0;
  while (i < n) {
    if (s[i] == p[j])
      ++i, ++j;
    if (j == m)
      ++count, j = lps[j - 1];
    else if (i < n && s[i] != p[j]) {
      if (j != 0)
        j = lps[j - 1];
      else
        ++i;
    }
  }
  return count;
}

int main() {
  string s, p;
  cin >> s >> p;
  cout << KMP(s, p) << '\n';
  return 0;
}

// =============================
// Rabin-Karp algorithm
// but has one TLE either
// =============================
/*
const ll d = 31;
const ll mod = 1e9 + 9;
ll computeHash(const string &p) {
  ll x = 0;
  for (char c : p)
    x = (x * d + c) % mod;
  return x;
}

int main() {
  string s, p;
  cin >> s >> p;
  int n = s.length(), m = p.length();

  if (n < m) {
    cout << 0 << '\n';
    return 0;
  }
  ll phash = computeHash(p);
  ll thash = computeHash(s.substr(0, m));

  vector<ll> power(m);
  power[0] = 1;
  for (int i = 1; i < m; ++i)
    power[i] = (d * power[i - 1]) % mod;

  int count = 0;
  if (phash == thash)
    ++count;

  for (int i = m; i < n; ++i) {
    thash = ((thash - power[m - 1] * s[i - m]) % mod + mod) % mod;
    thash = (thash * d + s[i]) % mod;
    if (phash == thash)
      ++count;
  }
  cout << count << '\n';
  return 0;
}
 */

// =============================
// simplest method but few TLE can't pass
// =============================
/*
int main() {
  string s, p;
  cin >> s >> p;
  int count = 0;
  for (size_t it = s.find(p); it != string::npos; it = s.find(p, it + 1))
    ++count;
  cout << count << '\n';
  return 0;
}
*/
