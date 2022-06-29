#include <iostream>
#include <map>

using namespace std;
int main() {
  int n;
  cin >> n;
  map<char, char> m;
  m['A'] = '2';
  m['B'] = '2';
  m['C'] = '2';
  m['D'] = '3';
  m['E'] = '3';
  m['F'] = '3';
  m['G'] = '4';
  m['H'] = '4';
  m['I'] = '4';
  m['J'] = '5';
  m['K'] = '5';
  m['L'] = '5';
  m['M'] = '6';
  m['N'] = '6';
  m['O'] = '6';
  m['P'] = '7';
  m['R'] = '7';
  m['S'] = '7';
  m['T'] = '8';
  m['U'] = '8';
  m['V'] = '8';
  m['W'] = '9';
  m['X'] = '9';
  m['Y'] = '9';
  map<string, int> m2;
  for (int i = 0; i < n; i++) {
    string s, s2;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      if (m.find(s[j]) != m.end()) {
        s2 += m[s[j]];
      } else if (s[j] == '-') {
        continue;
      } else {
        s2 += s[j];
      }
    }
    s2.insert(s2.begin()+3,'-');
    m2[s2] += 1;
    // cout << s2 << endl;
  }
  for (auto it = m2.begin(); it != m2.end(); it++) {
    if (it->second != 1) cout << it->first << " " << it->second << endl;
  }
}