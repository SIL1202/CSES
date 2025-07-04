// using trie + dp to solve this question
#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

class Trie {
public:
  Trie *children[26];
  bool terminal;

  Trie() {
    for (int i = 0; i < 26; ++i)
      children[i] = NULL;
    terminal = false;
  }

  void insert(string s) {
    Trie *root = this;
    for (char c : s) {
      int idx = c - 'a';
      if (!root->children[idx])
        root->children[idx] = new Trie();
      root = root->children[idx];
    }
    root->terminal = true;
  }
};

int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<string> vec(n);
  Trie *root = new Trie();
  for (string &v : vec) {
    cin >> v;
    root->insert(v);
  }

  vector<int> dp(s.size() + 1);
  dp[0] = 1;

  for (int i = 0; i < s.size(); ++i) {
    Trie *temp = root;
    for (int j = i; j < s.size(); ++j) {
      int idx = s[j] - 'a';
      if (!temp->children[idx])
        break;
      temp = temp->children[idx];
      if (temp->terminal)
        dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
    }
  }

  cout << dp[s.size()] << endl;
  return 0;
}
