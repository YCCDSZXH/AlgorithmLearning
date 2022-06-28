#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
  map<char, char> m;
  m['J'] = 'B';
  m['B'] = 'C';
  m['C'] = 'J';
  map<char, int> cnt[2];
  vector<vector<int>> v(2, vector<int>(3, 0));
  cnt[0]['J'] = cnt[0]['B'] = cnt[0]['C'] = 0;
  cnt[1]['J'] = cnt[1]['B'] = cnt[1]['C'] = 0;
  int n;
  cin >> n;
  char tmp1, tmp2;
  for (int i = 0; i < n; i++) {
    cin >> tmp1 >> tmp2;
    if (tmp1 == tmp2) {
      v[0][1]++;
      v[1][1]++;
    } else if (m[tmp1] == tmp2) {
      v[0][0]++;
      v[1][2]++;
      cnt[0][tmp1] += 100;
    } else {
      v[0][2]++;
      v[1][0]++;
      cnt[1][tmp2] += 100;
      // cnt[0][tmp1] -= 5;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }

  vector<pair<char, int>> vc[2];
  for (int i = 0; i < 2; i++) {
    for (auto it = cnt[i].begin(); it != cnt[i].end(); it++) {
      vc[i].push_back(make_pair(it->first, it->second));
    }
  }
  for (int i = 0; i < 2; i++) {
    sort(vc[i].begin(), vc[i].end(), [](pair<char, int> a, pair<char, int> b) {
      return a.second > b.second;
    });
  }
  cout << vc[0][0].first << " " << vc[1][0].first << endl;
}