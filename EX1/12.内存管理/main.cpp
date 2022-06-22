#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int n, m;  // n操作数,m 内存空间
  cin >> n >> m;
  string str[n];
  int numb[n];
  // cout << n << m;
  for (int i = 0; i < n; i++) {
    cin >> str[i];
    if (str[i][0] != 'd') {
      cin >> numb[i];
    } else {
      numb[i] = -1;
    }
  }
  int index = 0;
  int memory[m];
  for (int i = 0; i < m; i++) memory[i] = 0;
  int res = 1;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    bool sign = 0;
    switch (str[i][0]) {
      case 'd':
        sort(memory, memory + m, greater<int>());
        for (int j = 0; j < m; j++) {
          if (memory[j] == 0) {
            index = j;
            break;
          }
        }
        break;
      case 'e':
        for (int j = 0; j < m; j++) {
          if (memory[j] == numb[i]) {
            memory[j] = 0;
            sign = 1;
            continue;
          }
          if (sign) break;
        }
        break;
      case 'a':
        if (index + numb[i] > m) {
           cout << "NULL" << endl;
          break;
        }
        for (int j = index; j < index + numb[i]; j++)
          if (memory[j]) {
            sum = 1;
            break;
          }
        for (int j = index; j < index + numb[i]; j++) memory[j] = res;
        if (!sum) cout << res++ << endl;
        index += numb[i];
        break;
    }
  }
}