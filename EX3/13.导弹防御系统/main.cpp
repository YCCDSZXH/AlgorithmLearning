#include <iostream>
using namespace std;

const int N = 1010;
int a[N];
int f[N];
int n;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    f[i] = 1;
    for (int j = 0; j < i; j++)
      if (a[i] <= a[j]) f[i] = max(f[i], 1 + f[j]);
    res = max(res, f[i]);
  }

  cout << res << endl;

  int idx = 1;
  f[0] = a[0];
  for (int i = 1; i < n; i++) {
    // f是单调增的，用二分找到第一个大于等于a[i]的数的下标，找不到就新开一个反链
    int l = 0, r = idx - 1;
    while (l < r) {
      int m = l + (r - l >> 1);
      if (f[m] > a[i])
        r = m;
      else
        l = m + 1;
    }

    if (f[l] >= a[i])
      f[l] = a[i];
    else
      f[idx++] = a[i];
  }

  // cout << idx << endl;

  return 0;
}
