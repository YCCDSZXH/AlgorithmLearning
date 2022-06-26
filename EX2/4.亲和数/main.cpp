#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int get_another(int n) {
  vector<int>* child = new vector<int>();
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      child->push_back(i);
    }
  }
  int res = 0;
  for (int i = 0; i < child->size(); i++) {
    res += child->at(i);
  }
  return res;
}
int main() {
  int a, b;
  while (cin >> a >> b) {
    if (get_another(a) == b && get_another(b) == a) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}