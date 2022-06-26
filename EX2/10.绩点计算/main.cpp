#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  double n;
  cin >> n;
  vector<vector<double>> v(2);
  for (int i = 0; i < n; i++) {
    double a;
    cin >> a;
    v[0].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    double b;
    cin >> b;
    v[1].push_back(b);
  }
  double sum = 0;
  for (int i = 0; i < n; i++) {
    // sum += v[0][i]  ;
    if (v[1][i] < 60)
      sum += v[0][i] * 0;
    else if (v[1][i] < 64)
      sum += v[0][i] * 1.0;
    else if (v[1][i] < 68)
      sum += v[0][i] * 1.5;
    else if (v[1][i] < 72)
      sum += v[0][i] * 2.0;
    else if (v[1][i] < 75)
      sum += v[0][i] * 2.3;
    else if (v[1][i] < 78)
      sum += v[0][i] * 2.7;
    else if (v[1][i] < 82)
      sum += v[0][i] * 3.0;
    else if (v[1][i] < 85)
      sum += v[0][i] * 3.3;
    else if (v[1][i] < 90)
      sum += v[0][i] * 3.7;
    else
      sum += v[0][i] * 4.0;
  }
  double sum2 = 0;
  for (int i = 0; i < n; i++) {
    sum2 += v[0][i];
  }
  cout << setprecision(2) << fixed<< sum / sum2 << endl;
}