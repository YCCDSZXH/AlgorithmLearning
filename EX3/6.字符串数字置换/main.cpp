#include <iostream>
#include <map>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  int i = 0;
  map<char, string> m;
  m['0'] = "(Zero)";
  m['1'] = "(One)";
  m['2'] = "(Two)";
  m['3'] = "(Three)";
  m['4'] = "(Four)";
  m['5'] = "(Five)";
  m['6'] = "(Six)";
  m['7'] = "(Seven)";
  m['8'] = "(Eight)";
  m['9'] = "(Nine)";
  int arr[10];
  for(int i  =0 ; i < 10; i++) {
    arr[i] = 0;
  }
  for (int i = 0; i < s.size(); i++) {
    if (m.find(s[i]) != m.end()) {
      cout << m[s[i]];
      arr[s[i] - '0'] += 1;
    } else {
      cout << s[i];
    }
  }
  cout << endl;
  for(int i = 0; i < 10; i++) {
    cout << arr[i] << ' ';
  }
  return 0;
}
