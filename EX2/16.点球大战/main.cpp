#include <iostream>
#include <vector>
using namespace std;
void print_res(vector<string> &v) {
    
}

int main() {
  int n;
  cin >> n;
  getchar();
  while (n) {
    string tmp;
    vector<string> v[2];
    for (int i = 0; i < n; i++) {
      getline(cin, tmp);
      v[i % 2].push_back(tmp);
    }

    cin >> n;
    getchar();
  }
}