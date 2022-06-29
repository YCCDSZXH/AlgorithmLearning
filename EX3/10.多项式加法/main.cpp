#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int main() {
  map<int, int,greater<int>> m;
  for (int i = 0; i < 2; i++) {
    int tmp1, tmp2;
    while (cin >> tmp1 >> tmp2) {
      if (tmp1 == 0 && tmp2 == 0) break;
      m[tmp1] += tmp2;
    }
  }
  for (auto it = m.begin(); it != m.end(); it++) {
    if(it->second!=0)
      cout << it->first << ' ' << it->second << endl;
  }
}