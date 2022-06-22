#include <iostream>
#include <map>
using namespace std;
int main() {
  map<int, int> m;
  int task, n;
  cin >> task >> n;
  // cout << task << " " << n << endl;
  int numb[task];
  int endsize = n;
  string task_name[task];
  for (int i = 0; i < task; i++) {
    cin >> task_name[i];
    if (task_name[i][0] != 'd') {
      cin >> numb[i];
    }
  }
  // for(int i = 0; i < task; i++) {
  //   cout << task_name[i] << ' ' << numb[i]<< endl;
  // }
  int count = 1;
  for (int i = 0; i < task; i++) {
    switch (task_name[i][0]) {
      case 'a':
        if (endsize >= numb[i]) {
          m[count] = numb[i];
          cout << count << endl;
          count++;
          endsize -= numb[i];
        }else{
          cout << "NULL" << endl;
        }
        break;
      case 'e':
        if (m.find(count-1) != m.end()) {
          endsize += m[count-1];
        }

        if (m.find(numb[i]) != m.end()) {
          m.erase(numb[i]);
        } else {
          cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
        }

        break;
      case 'd':
        endsize = n;
        for (auto it = m.begin(); it != m.end(); it++) {
          endsize -= it->second;
        }
        break;
    }
  }
}

// 14 100
// alloc 99  1
// alloc 1   2
// alloc 1   null
// erase 2   
// alloc 1   3
// erase 4   iiii
// erase 1   
// alloc 100 null
// alloc 1   4
// alloc 99
// defragment 
// erase 4
// alloc 100
// alloc 99