#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
void adjust_str(string& tmp) {
  for (int i = 0; i < tmp.size(); i++) {
    if (tmp[i] >= 'A' && tmp[i] <= 'Z') {
      tmp[i] = tmp[i] + 32;
    }
  }
}
void add_to_database(
    map<string, int>::iterator iter,
    map<string, vector<map<string, int>::iterator>>& database) {
  // 将iter指向的元素添加到数据库中
  string tmp = iter->first;
  adjust_str(tmp);
  vector<string> v;
  int next = 0;
  for (int i = 0; i < tmp.size(); i++) {
    if (tmp[i] == ' ') {
      v.push_back(tmp.substr(i + 1));
      next = i;
    }

    if (i == tmp.size() - 1) {
      if (next == tmp.length()) {
        v.push_back(tmp);
        break;
      }
      v.push_back(tmp);
      tmp = tmp.substr(0, next);
      i = 0;
    }
  }
  for (int i = 0; i < v.size(); i++) {
    database[v[i]].push_back(iter);
  }
}
int main() {
  int n;
  cin >> n;
  string tmp;
  int tmp2;
  map<string, int> m;
  map<string, vector<map<string, int>::iterator>> database;
  for (int i = 0; i < n; i++) {
    getchar();
    getline(cin, tmp);
    scanf("%d", &tmp2);
    m[tmp] = tmp2;
    add_to_database(m.find(tmp), database);
  }
  // string s;
  cin >> n;
  while (n) {
    getchar();
    for (int i = 0; i < n; i++) {
      getline(cin, tmp);
      adjust_str(tmp);
      sort(database[tmp].begin(), database[tmp].end(),
           [](map<string, int>::iterator a, map<string, int>::iterator b) {
             return a->second > b->second;
           });
      for (auto iter = database[tmp].begin(); iter != database[tmp].end();
           iter++) {
        cout << (*iter)->first << endl;
      }
      cout << "***" << endl;
    }
    cout << "---" << endl;
    cin >> n;
  }
}

/*
6
Finding the Shortest Path 
120
Finding the k Shortest Path 
80
Find Augmenting Path in General Graph 
80
Matching in Bipartite Graph 
200
Finding kth Shortest Path 
50
Graph Theory and its Applications 
40
6
shortest path
*/