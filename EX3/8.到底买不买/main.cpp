#include <iostream>
#include <map>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  map<char, int> m1;
  map<char, int> m2;
  for (int i = 0; i < s1.size(); i++) {
    m1[s1[i]]++;
  }
  for (int i = 0; i < s2.size(); i++) {
    m2[s2[i]]++;
  }
  int less = 0, sum = 0;
  for (auto it = m2.begin(); it != m2.end(); it++) {
    if (m1.find(it->first) == m1.end()) {
      less += it->second;
    } else if (m1[it->first] < it->second) {
      less += it->second - m1[it->first];
    } else {
      sum += it->second;
    }
  }
  if (less) {
    cout << "No" << ' ' << less << endl;
  }else{
    cout << "Yes" << ' ' << s1.length()-sum << endl;
  }
}
