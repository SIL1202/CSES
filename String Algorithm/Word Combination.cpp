#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
#define MOD 1000000007

unordered_map<string, bool> mp;
string input;
int n;
vector<int> dp;

int combination(int index) {
  if (index == input.size())
    return 1;
  if (dp[index] != -1)
    return dp[index];

  int ans = 0;
  for (int len = 1; len + index <= input.size(); len++) {
    string word = input.substr(index, len);
    if (mp[word]) {
      ans = (ans + combination(index + len)) % MOD;
    }
  }
  return dp[index] = ans;
}

int main() {
  cin >> input;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string word;
    cin >> word;
    mp[word] = true;
  }

  dp.assign(input.size() + 1, -1);
  cout << combination(0);
  return 0;
}
