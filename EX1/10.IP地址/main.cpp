#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;
// string to int
int str2int(string str) {
    int res = 0;
    for (int i = 0; i < str.size(); i++) {
        res = res * 10 + str[i] - '0';
    }
    return res;
}
// 转换为二进制
string int2bin(int num) {
    string res = "";
    while (num) {
        res = to_string(num % 2) + res;
        num /= 2;
    }
    return res;
}
int main() {
  vector<int> res;
  int n;
  cin >> n;
  string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    str.append(".");
    int str_index = 0, numb[4], Numb_index = 0;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == '.') {
        numb[Numb_index++]= str2int(str.substr(str_index, i - str_index));
        str_index = i + 1;
      }
    }
    for(int i = 0; i < 4; i++) {
      while(numb[i] > 0) {
        res.push_back(numb[i] % 2);
        numb[i] /= 2;
      }
    }
    cout << accumulate(res.begin(),res.end(),0) << endl;
    res.clear();
  }
}