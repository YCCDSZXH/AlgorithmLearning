#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  string data[2];
  int left = 0;
  for (int i = 0; i < n; i++) {
    cin >> data[0] >> data[1];
    if (data[0][0] == '-') left++;
  }
  // for (int i = 0; i < n; i++) {
  //   cout << data[0] << data[1];
  // }

  if ((n - left) == 1 || left == 1 || left == 0 || (n - left) == 0)
    cout << "Yes";
  else
    cout << "No";
}