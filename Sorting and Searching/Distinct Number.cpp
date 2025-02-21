#include <iostream>
#include <set> //從unordered_set 改成 set避免碰撞

using namespace std;

int main() {
  set<long long> uset;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    uset.insert(num);
  }

  cout << uset.size() << endl;
}
