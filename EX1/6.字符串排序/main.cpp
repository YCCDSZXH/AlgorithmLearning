#include <algorithm>
#include <iostream>
using namespace std;
struct dataa {
  /* data */
  string str;
  long long value;
};

bool com(dataa A, dataa B) {
    if (B.value > A.value)
      return true;
    else
      return false;
}
int getValue(string A) {
  int tmp = 0;
  for (int i = 0; i < A.length(); i++) {
    for (int j = i+1; j < A.length(); j++) {
      if (A[i] > A[j]) {
        ++tmp;
      }
    }
  }
  return tmp;
}


int main() {
  int n, m;
  cin >> n >> m;
  // string str[m];
  // int value[m];
  struct dataa d[m];
  for (int i = 0; i < m; i++) {
    cin >> d[i].str;
    d[i].value = getValue(d[i].str);
    // cout << d[i].value << "|||";
  }
  // for (int i = 0; i < m; i++) {
  //   // cin >> d[i].str;
  //   // d[i].value = getValue(d[i].str);
  //   cout << d[i].value << "|||";
  // }
  sort(d, d+m, com);
  for (int i = 0; i < m; i++) {
    cout << d[i].str << endl;
  }
}