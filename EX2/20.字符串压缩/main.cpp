#include <iostream>
#include <set>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  // cout << n << ' ' << a << ' ' << b << '\n';
  string str;
  cin >> str;
  // cout << str << endl;
  bool add = false;
  int res = 0;
  for (int i = 0; i < str.size(); i++) {
    add = false;
    for (int j = i - 1; j >= 0; j--) {
      // cout << str.substr(0, i) << ' ' << str.substr(i, j + 1) << endl;
      if (i + j > str.size()) continue;
      if (str.substr(0, i).find(str.substr(i, j + 1)) != string::npos) {
        // cout << str.substr(0, i) << ' ' << str.substr(i, j + 1) << endl;
        add = true;
        if ((j + 1) * a > b) {
          res += b;
          i += j;
        } else {
          res += a;
        }
        break;
      }
    }
    if (!add) res += a;
  }
  cout << res;
}