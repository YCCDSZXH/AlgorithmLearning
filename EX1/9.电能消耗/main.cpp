#include <iostream>
using namespace std;
int main() {
  int n, P1, P2, P3, T1, T2;
  cin >> n >> P1 >> P2 >> P3 >> T1 >> T2;
  int arr[n][2];
  int res = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1];
    res += (arr[i][1] - arr[i][0]) * P1;
  }
  int tmp;
  for (int i = 1; i < n; i++) {
    tmp = arr[i][0] - arr[i - 1][1];
    if (tmp <= T1) {
      res += tmp * P1;
    } else if (tmp <= T1 + T2) {
      res += T1 * P1;
      res += (tmp - T1) * P2;
    } else {
      res += (T1 * P1 +T2*P2 +(tmp-T1-T2)*P3);
    }
  }
  cout << res;
}
// 
// 10 40 60