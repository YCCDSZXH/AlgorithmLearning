#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
struct Paper {
  string forS;
  string title;
  int num;
};
bool Find(string x, string y) {
  stringstream st;
  st.str(y);
  string l, r;
  int flag1 = 0, flag2 = 0;
  while (st >> r) {
    flag1++;
    stringstream ss;
    ss.str(x);
    while (ss >> l) {
      if (l == r) flag2++;
    }
  }
  if (flag1 == flag2)  //每个关键词都要有
    return true;
  return false;
}
bool cmp(Paper l, Paper r) {
  if (l.num != r.num) return l.num > r.num;
  return false;
}
string Trans(string tmp, int l) {
  for (int k = 0; k < l; k++)
    if (tmp[k] >= 'A' && tmp[k] <= 'Z') tmp[k] += 32;
  return tmp;
}
int main() {
  int n, m;
  while (cin >> n) {
    if (n == 0) break;
    Paper a[n];
    for (int i = 0; i < n; i++) {
      getchar();
      string s;
      int t;
      getline(cin, s);
      int len = s.length();
      a[i].forS = Trans(s, len);
      a[i].title = s;
      cin >> t;
      a[i].num = t;
    }
    cin >> m;
    sort(a, a + n, cmp);
    getchar();
    for (int i = 0; i < m; i++) {
      string str;
      getline(cin, str);
      for (int j = 0; j < n; j++) {
        if (Find(a[j].forS, str)) cout << a[j].title << '\n';
      }
      cout << "***" << '\n';
    }
    cout << "---" << '\n';
  }
  return 0;
}