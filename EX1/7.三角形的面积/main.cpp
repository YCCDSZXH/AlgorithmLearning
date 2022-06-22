#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
long double getlength(int x, int y, int x1, int y1) {
  return sqrt(pow(abs(x - x1), 2) + pow(abs(y - y1), 2));
}
int main() {
  int x1, y1, x2, y2, x3, y3;
  long double a, b, c, s;
  while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
    if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0)return 0;
    a = getlength(x1, y1, x2, y2);
    b = getlength(x1, y1, x3, y3);
    c = getlength(x3, y3, x2, y2);
    s = (a + b + c) / 2;
    // cout << a << " "<< b << " "<< c << " " << endl;
    cout << setprecision(6) << fixed << sqrt(s * (s - a) * (s - b) * (s - c))
         << endl;
  }
}