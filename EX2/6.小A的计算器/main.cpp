#include <iostream>
using namespace std;
string add(string& A, string& B) {
  string res = "";

  int i = A.size() - 1;
  int j = B.size() - 1;
  int index = 0;
  while (1) {
    if(i >= 0 && j >= 0){
      int a = A[i] - 'a';
      int b = B[j] - 'a';
      int sum = a + b + index;
      res = char(sum % 26 + 'a') + res;
      index = sum / 26;
      i--;
      j--;
    } else if(i >= 0){
      int a = A[i] - 'a';
      int sum = a + index;
      res = char(sum % 26 + 'a') + res;
      index = sum / 26;
      i--;
    } else if(j >= 0){
      int b = B[j] - 'a';
      int sum = b + index;
      res = char(sum % 26 + 'a') + res;
      index = sum / 26;
      j--;
    } else {
      if(index == 1)
        res = (char)96 + res;
      break;
    }
  }

  return res;
}
int main() {
  int n;
  cin >> n;
  string str1, str2;
  for (int i = 0; i < n; i++) {
    cin >> str1 >> str2;
    cout << add(str1, str2) << endl;
  }
}