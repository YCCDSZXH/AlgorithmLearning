#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
  string s;
  cin >> s;
  map<char, string> m;
  m['0'] = "ling";
  m['1'] = "yi";
  m['2'] = "er";
  m['3'] = "san";
  m['4'] = "si";
  m['5'] = "wu";
  m['6'] = "liu";
  m['7'] = "qi";
  m['8'] = "ba";
  m['9'] = "jiu";
  int res = 0;
  for (int i = 0; i < s.size(); i++) {
    res += s[i] - '0';
  }
  string res_str = to_string(res);
  for (int i = 0; i < res_str.size(); i++) {
    cout << m[res_str[i]] << ' ';
  }
}