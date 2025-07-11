#include <iostream>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> lps(n);
  for (int i = 1, j = 0; i < n;) {
    if (s[i] == s[j])
      lps[i++] = ++j;
    else
      j ? j = lps[j - 1] : lps[i++] = 0;
  }

  // 建立 lps 陣列：
  // lps[i] 表示 s[0...i] 這段字串中，
  // "最長的前綴（prefix）同時也是後綴（suffix）" 的長度。
  //
  // 為什麼跟題目有關？
  // 因為 lps[n-1] 代表整個字串 s 的最長 border 長度，
  // 而 lps[lps[n-1] - 1] 則是次長 border，
  // 一直往回推，就可以找到所有 border 長度。
  //
  // 這比直接暴力比對 substr(0, len) 和 substr(n-len, len) 更快，
  // 時間複雜度 O(n)！

  vector<int> res;
  int len = lps[n - 1];
  while (len > 0) {
    res.push_back(len);
    len = lps[len - 1];
  }
  for (int i = res.size() - 1; i >= 0; --i)
    cout << res[i] << ' ';
  return 0;
}
