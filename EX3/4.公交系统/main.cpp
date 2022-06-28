#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int arr[a];
  for (int i = 0; i < a; i++) {
    cin >> arr[i];
  }
  int sum = 0;
  int max = 0, min = 0;

  for (int i = 0; i < a; i++) {
    sum += arr[i];
    if (sum > max) {
      max = sum;
    }
    if (sum < min) {
      min = sum;
    }
  }

  cout << ((b - max + min + 1) > 0 ? (b - max + min + 1) : 0) << endl;
}