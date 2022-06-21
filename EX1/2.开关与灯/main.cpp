#include <iostream>
using namespace std;
int main() {
  int n, m;  // n = 4 ,m = 5
  cin >> n >> m;
  string* list = new string [n];
  for (int i = 0; i < n; i++) {
    cin >> list[i];
  }
  int array[n+1][m];
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      array[i][j] = (int)list[i][j]-48;
    }
  }
  
  // for (int i = 0; i < m; i++) {
  //   int count = 0;
  //   for (int j = 0; j < m; j++) {
  //     if (array[i] == array[j]) {
  //       count++;
  //     }
  //   }
  // }
  /*
4 8
10010110 
10101000 
11010100 
10000101
*/
  for(int i = 0; i < m; i++) {
    array[n][i] = 0;

    for(int j = 0; j < n; j++) {
      array[n][i] += array[j][i];
    }
  }
  // for(int i = 0; i < n+1; i++) {
  //   for(int j = 0; j < m; j++) {
  //     cout << array[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  for(int i = 0; i < n; i++) {
    bool sign = 0;
    for(int j = 0; j < m; j++) {
      if(array[n][j]==array[i][j]){
        sign = 1;
      }
    }
    if(sign == 0){
      cout << "YES" << endl;
      return 1;
    }
  }
  cout << "NO" << endl;
  return 0;
}