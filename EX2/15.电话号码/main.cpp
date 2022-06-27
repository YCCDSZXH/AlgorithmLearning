#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
struct cmp {
  bool operator()(const string& a, const string& b) {
    if (a.size() != b.size()) {
      return a.size() < b.size();
    } else {
      for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
          return a[i] < b[i];
        }
      }
    }
    return 0;
  }
};
int main() {
  map<string, set<string, cmp>> phoneBook;
  string name, phone;
  map<string, map<string, int>> m1;
  int m;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> name >> m;
    for (int j = 0; j < m; j++) {
      cin >> phone;
      phoneBook[name].insert(phone);
    }
  }
  cout << phoneBook.size() << endl;
  for (auto it = phoneBook.begin(); it != phoneBook.end(); it++) {
    for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
      for (int i = 1; i < it2->size(); i++) {
        m1[it->first][it2->substr(i)] = 0;
      }
    }
  }

  for (auto it = phoneBook.begin(); it != phoneBook.end(); it++) {
    vector<string> v;
    for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
      if (m1[it->first].find(*it2) != m1[it->first].end()) {
        v.push_back(*it2);
      }
    }
    for (int i = 0; i < v.size(); i++) {
      phoneBook[it->first].erase(v[i]);
    }
    v.clear();
  }
  for (auto it = phoneBook.begin(); it != phoneBook.end(); it++) {
    cout << it->first << " " << it->second.size() << ' ';
    for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
      cout << *it2 << " ";
    }
    cout << endl;
  }
  return 0;
}