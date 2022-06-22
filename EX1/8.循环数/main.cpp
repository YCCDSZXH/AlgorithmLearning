#include <iostream>
using namespace std;
void add(int*& A, int*& B, int length) {
  for (int i = length - 1; i >= 0; i--) {
    A[i] = A[i] + B[i];
    if (A[i] > 9) {
      A[i - 1] += A[i] / 10;
      A[i] = A[i] % 10;
    }
  }
}
bool test(int*& A, int*& B, int length) {
  add(A, B, length);
  for (int i = 0; i < length; i++) {
    bool ok = 1;
    for (int j = 0; j < length; j++) {
      if (A[j] != B[(j + i)%length]) {
        ok = 0;
        break;
      }
    }
    if (ok) return 1;
  }
  return 0;
}
int main() {
  int n;
  string numbstr;
  cin >> numbstr;
  n = numbstr.length();
  int* numb = new int[n];
  for (int i = 0; i < n; i++) {
    numb[i] = numbstr[i] - 48;
  }

  int* res = new int[n];
  for(int i = 0; i < n;i++){
    if(!test(res,numb,n)){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 1;
}