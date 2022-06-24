#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
bool cmp_by_1(const pair<string, int *> &a, const pair<string, int *> &b) {
  if (a.second[10] != b.second[10]) return a.second[10] > b.second[10];
  for (int i = 0; i < 10; i++) {
    if (a.second[i] != b.second[i]) return a.second[i] > b.second[i];
  }
}
bool cmp_by_2(const pair<string, int *> &a, const pair<string, int *> &b) {
  for (int i = 0; i < 10; i++) {
    if (a.second[i] != b.second[i]) return a.second[i] > b.second[i];
  }
}
int main() {
  // map<string,int> m;
  // unordered_map<int,int> m;
  int score_list[11] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1, 0};
  map<string, int *> m1;
  // map<string, int> m2;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    string tmp_str;
    for (int j = 0; j < m; j++) {
      cin >> tmp_str;
      if (m1.find(tmp_str) == m1.end()) m1[tmp_str] = new int[11];
      m1[tmp_str][j]++;
    }
  }

  vector<pair<string, int *>> v;
  for (auto it = m1.begin(); it != m1.end(); it++) {
    for (int i = 0; i < 10; i++) {
      it->second[10] += score_list[i] * it->second[i];
    }
    v.push_back(make_pair(it->first, it->second));
    // m1.erase(it->first);
  }

  // sort(v.begin(), v.end(), cmp_by_1);
  // cout << v[0].first << endl;
  // sort(v.begin(), v.end(), cmp_by_2);
  // cout << v[0].first << endl;
  pair<string, int *> max = v[0];
  for (auto it = v.begin(); it != v.end(); it++) {
    if (!cmp_by_1(max, *it)) max = *it;
  }
  cout << max.first << endl;
  for (auto it = v.begin(); it != v.end(); it++) {
    if (!cmp_by_2(max, *it)) max = *it;
  }
  cout << max.first << endl;
}