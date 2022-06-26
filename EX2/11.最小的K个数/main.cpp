#include <iostream>
#include <set>
using namespace std;
int main() {
  long long m, n;
  cin >> m >> n;
  set<long long> s;
  long long tmp;
  for (long long i = 0; i < m; i++) {
    cin >> tmp;
    s.insert(tmp);
  }
  int i = 0;
  for (auto it = s.begin(); it != s.end() && i < n; it++, i++) {
    cout << *it << " ";
  }
}