#include <iostream>
#include <map>
using namespace std;
int main() {
  map<string, int> m;
  m["monday"] = 1;
  m["tuesday"] = 2;
  m["wednesday"] = 3;
  m["thursday"] = 4;
  m["friday"] = 5;
  m["saturday"] = 6;
  m["sunday"] = 7;
  // m["monday"] += 1;
  int n;
  cin >> n;
  string S, E;
  int l, r;
  for (int i = 0; i < n; i++) {
    cin >> S >> E >> l >> r;
    // cout << S << E << l << r << endl;
    int tmp = (m[E] - m[S]) + 1;

    while (tmp < l) {
      tmp += 7;
    }
    if (tmp > r)
      cout << "impossible" << endl;
    else if (tmp + 7 <= r)
      cout << "many" << endl;
    else
      cout << tmp << endl;
  }
  return 0;
}
