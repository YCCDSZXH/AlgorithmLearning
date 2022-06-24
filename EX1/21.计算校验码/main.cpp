#include <cmath>
#include <iostream>
#include <map>
using namespace std;
char mod(string str, int n, map<char, int> m) {
  int tmp = 0;
  tmp += (m[str[0]] + m[str[1]] * (n + 1)) % n;
  return tmp >= 10 ? tmp - 10 + 'a' : tmp + '0';
}
int main() {
  map<char, int> m;
  m['1'] = 1;
  m['2'] = 2;
  m['3'] = 3;
  m['4'] = 4;
  m['5'] = 5;
  m['6'] = 6;
  m['7'] = 7;
  m['8'] = 8;
  m['9'] = 9;
  m['0'] = 0;
  m['a'] = 10;
  m['b'] = 11;
  m['c'] = 12;
  m['d'] = 13;
  m['e'] = 14;
  m['f'] = 15;
  int n;
  cin >> n;
  int uprule = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> uprule >> s;
    // cout << uprule << " " << s << endl;
    // long long sum = 0;
    // for (int j = 0; j < s.length(); j++) {
    //   sum += m[s[j]] * (long long)pow(uprule, s.length() - j);
    // }
    // long long res = (sum % (uprule - 1) == 0 ? 0 : uprule - 1 - sum % (uprule
    // - 1)); cout << sum << ' ' << res << endl; cout << (char)(res >= 10 ? 'a'
    // + res - 10 : res + '0') << endl;
    s += '0';
    string tmp;
    for (int j = 1; j < s.length(); j++) {
      tmp[0] = s[j];
      tmp[1] = s[j - 1];
      s[j - 1] = '0';
      s[j] = mod(tmp, uprule - 1, m);
    }
    int res = (m[s[s.length() - 1]] == 0 ? m[s[s.length() - 1]]
                                         : uprule - 1 - m[s[s.length() - 1]]);
    cout << (char)(res >= 10 ? res - 10 + 'a' : res + '0') << endl;
  }
}