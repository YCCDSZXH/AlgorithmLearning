#include <iostream>
#include <map>
using namespace std;
int main() {
  int m1;
  cin >> m1;
  while (m1) {
    map<string, int> m;
    for (int i = 0; i < 2 * m1 - 1; i++) {
      string s;
      // scanf("%s", &s);
      cin >> s;
      if (m.find(s) != m.end()) {
        m.erase(s);
      } else {
        m[s] = 1;
      }
    }
    for (auto it = m.begin(); it != m.end(); it++) {
      cout << it->first << endl;
    }
    cin >> m1;
  }
}