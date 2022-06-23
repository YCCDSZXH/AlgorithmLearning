#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct score {
  int fs;
  int ss;
  int ts;
  void print() { cout << fs << " " << ss << " " << ts << endl; }
};
int str2int(string str) {
  int res = 0;
  for (int i = 0; i < str.size(); i++) {
    res = res * 10 + str[i] - '0';
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  map<string, score> m;
  string tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    m[tmp].fs = 0;
    m[tmp].ss = 0;
    m[tmp].ts = 0;
  }
  getchar();
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    string team1, team2;
    string tmp1, tmp2;
    int score1, score2;
    // scanf("%s,-,%s, ,%d,:,%d", &team1[0], &team2[0], &score1, &score2);
    cin >> tmp1 >> tmp2;
    // cout << tmp1 << " " << tmp2 << endl;
    for (int i = 0; i < tmp1.size(); i++) {
      if (tmp1[i] == '-') {
        team1 = tmp1.substr(0, i);
        team2 = tmp1.substr(i + 1);
        break;
      }
    }
    for (int i = 0; i < tmp2.size(); i++) {
      if (tmp2[i] == ':') {
        score1 = str2int(tmp2.substr(0, i));
        score2 = str2int(tmp2.substr(i + 1));
        break;
      }
    }
    m[team1].ts += score1;
    m[team2].ts += score2;
    if (score1 > score2) {
      m[team1].fs += 3;
      m[team1].ss += (score1 - score2);
      m[team2].ss -= (score1 - score2);
    } else if (score1 == score2) {
      m[team1].fs++;
      m[team2].fs++;
    } else {
      m[team2].fs += 3;
      m[team2].ss += (score2 - score1);
      m[team1].ss -= (score2 - score1);
    }
  }
  vector<pair<string, score>> v;
  for (auto it = m.begin(); it != m.end(); it++) {
    v.push_back(make_pair(it->first, it->second));
  }
  sort(v.begin(), v.end(),
       [](const pair<string, score> &a, const pair<string, score> &b) {
         if (a.second.fs > b.second.fs)
           return true;
         else if (a.second.fs == b.second.fs)
           if (a.second.ss > b.second.ss)
             return true;
           else if (a.second.ss == b.second.ss)
             if (a.second.ts > b.second.ts) return true;
         return false;
       });
  // for (auto it = v.begin(); it != v.end(); it++) {
  //   cout << it->first << " ";
  //   it->second.print();
  // }
  // cout << v[0].first << endl << v[1].first << endl;
  sort(v.begin(),v.begin()+n/2,[](const pair<string,score>&a,const pair<string,score>&b){
    return a.first<b.first;
  });
  for (int i = 0; i < n / 2; i++) {
    cout << v[i].first << endl;
  }
}
