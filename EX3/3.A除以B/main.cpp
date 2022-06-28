#include <iostream>
using namespace std;
int main() {
  string numb1;
  int numb2;
  cin >> numb1 >> numb2;
  int arr[numb1.size()];
  for (int i = 0; i < numb1.size(); i++) {
    arr[i] = numb1[i] - '0';
  }

  int tmp = 0;
  for (int i = 0; i < numb1.size(); i++) {
    arr[i] += tmp * 10;
    tmp = arr[i] % numb2;
    arr[i] = arr[i] / numb2;
  }
  if(numb1.size() == 1){
    cout << arr[0] << ' '<<tmp;
    return 0;
  }
  if (arr[0] == 0) {
    for (int i = 1; i < numb1.size(); i++) {
      cout << arr[i];
    }
    cout << ' ' << tmp;
  } else {
    for (int i = 0; i < numb1.size(); i++) {
      cout << arr[i];
    }
    cout << ' ' << tmp;
  }
}