#include <iostream>
using namespace std;
int main() {
  long long n;
  cin >> n;
  while (n) {
    int i = 0;
    while (n != 1) {
      if (n % 2 == 0) {
        n /= 2;
      } else {
        n = (3 * n + 1)/2;
      }
      i++;
    // cout << n << ' ';
    }
    cout << i << endl;
    cin >> n;
  }
}