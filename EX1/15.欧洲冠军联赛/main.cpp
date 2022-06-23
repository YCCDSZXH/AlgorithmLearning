#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct score {
  int fiscore;
  int sescore;
  void print() {
    cout << "fis" << fiscore << " "
         << "ses" << sescore << endl;
  }
  bool operator>(score const &r) const {
    //这个函数指定排序策略，按iID排序，如果iID相等的话，按strName排序
    if (fiscore > r.fiscore) return true;
    if (fiscore == r.fiscore) return sescore > r.sescore;
    return false;
  }
};
typedef pair<string, score> pii;
bool comp(const pii &a, const pii &b) { return a.second > b.second; }
int main() {
  map<string, score> m;
  // map<string, int> mscore;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 12; j++) {
      string team1, team2;
      int score1, score2;
      cin >> team1 >> score1 >> team2 >> score2 >> team2;
      if (score1 > score2) {
        m[team1].fiscore += 3;
        m[team1].sescore += (score1 - score2);
        m[team2].sescore -= (score1 - score2);
      } else if (score1 == score2) {
        m[team1].fiscore++;
        m[team2].fiscore++;
      } else {
        m[team2].fiscore += 3;
        m[team2].sescore += (score2 - score1);
        m[team2].sescore -= (score2 - score1);
      }
    }
    // cout << 1 << endl;
    // for (auto it = m.begin(); it != m.end(); it++) {
    //   cout << it->first << " ";
    //   it->second.print();
    //   cout << endl;
    // }
    vector<pii> v;

    for (auto it = m.begin(); it != m.end(); it++) {
      v.push_back(make_pair(it->first, it->second));
    }
    sort(v.begin(), v.end(), comp);
    // for (auto it = v.begin(); it != v.end(); it++) {
    //   cout << it->first << " ";
    //   it->second.print();
    //   cout << endl;
    // }
    cout << v[0].first << " " << v[1].first << endl;

    m.clear();
  }
}