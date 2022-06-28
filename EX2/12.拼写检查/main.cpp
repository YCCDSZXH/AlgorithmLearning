// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<string, int> m;  //使用map可以将查找复杂度降为O（1）
struct item {
  string s;
  int num;  //要按顺序输出，用以查找完后排序
};
vector<item> v;
bool cmp(item a, item b) { return a.num < b.num; }
void serase(string a) {  //删除某个字母
  for (int i = 0; i < a.size(); i++) {
    string b = a;
    item x;
    b.erase(b.begin() + i);
    if (m[b]) {
      x.s = b;
      x.num = m[b];
      v.push_back(x);
    }
  }
}
void sreplace(string a) {  //依次替换某个字母
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < 26; j++) {
      string b = a;
      item x;
      b[i] = char('a' + j);
      if (m[b]) {
        x.s = b;
        x.num = m[b];
        v.push_back(x);
      }
    }
  }
}
void sinsert(string a) {  //插入某个字母
  for (int i = 0; i <= a.size(); i++) {
    for (int j = 0; j < 26; j++) {
      string b = a;
      item x;
      b.insert(i, 1, char('a' + j));
      if (m[b]) {
        x.s = b;
        x.num = m[b];
        v.push_back(x);
      }
    }
  }
}
int main() {
  string a;
  int t = 1;
  while (cin >> a) {
    if (a[0] == '#') break;
    m[a] = t++;
  }
  while (cin >> a) {
    v.clear();
    if (a[0] == '#') break;
    if (m[a])
      cout << a << " is correct" << endl;
    else {
      cout << a << ":";
      serase(a);
      sinsert(a);
      sreplace(a);

      sort(v.begin(), v.end(), cmp);
      for (int i = 0; i < v.size(); i++) {
        cout << ' ' << v[i].s;
      }
      cout << endl;
    }
  }
  return 0;
}