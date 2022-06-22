#include <iostream>
#include <string>
using namespace std;
int main() {
  string str;
  int m, n;  //需要查找的是 n 的倍数和包含 n
  cin >> m >> n;
  string nstr = to_string(n);
  for (int i = 1; i < m; i++) {
    str = to_string(i);
    // cout << str << endl;
    // cout << str.find_first_of(nstr) << endl;
    if(i%n == 0||str.find(nstr)!= string::npos){
      cout << i << ' ';
    }
  }
}