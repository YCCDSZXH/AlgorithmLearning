#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    int arr[a];
    int res[a], max = 0;
    for (int j = 0; j < a; j++) {
      cin >> arr[j];
    }
    for (int j = 0; j < a; j++) {
      res[j] = 0;
      int k = j;
      while (k < a) {
        res[j] += arr[k];
        k += arr[k];
      }
    }
    for (int j = 0; j < a; j++) {
      if (res[j] > max) max = res[j];
    }
    cout << max << endl;
  }
}