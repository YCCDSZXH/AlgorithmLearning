#include <iostream>
using namespace std;
// string转 int
int str2int(string s) {
  int res = 0;
  for (int i = 0; i < s.size(); i++) {
    res = res * 10 + (s[i] - '0');
  }
  return res;
}
int main() {
  string a, b,a2,b2;
  char a1, b1;
  cin >> a >> a1 >> b >> b1;
  for(int i = 0; i < a.size(); i++) {
    if(a[i] == a1) {
       a2+=a1;
    }
  }
  for(int i = 0; i < b.size(); i++) {
    if(b[i] == b1) {
       b2+=b1;
    }
  }
  int a3 = str2int(a2);
  int b3 = str2int(b2);
  cout << a3 + b3 << endl;
}