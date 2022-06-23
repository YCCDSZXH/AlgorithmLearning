#include <iostream>
#include <map>
#include <stack>
using namespace std;
;
int main() {
  map<char, char> m;
  stack<char> s;
  m[')'] = '(';
  m[']'] = '[';
  m['}'] = '{';
  m['>'] = '<';

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    bool sign = 0;
    while(!s.empty()) s.pop();
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
      if (m.find(str[i]) == m.end()) {
        s.push(str[i]);
      } else {
        if (s.empty()) {
          cout << "No" << endl;
          sign = 1;
          break;
        }
        if (s.top() != m[str[i]]) {
          cout << "No" << endl;
          sign = 1;
          break;
        }
        s.pop();
      }
    }
    if (sign == 1) continue;
    if (s.empty())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    
  }
}