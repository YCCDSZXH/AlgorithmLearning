#include <iostream>
#include <map>
using namespace std;
int main() {
  map<int, int> map;
  while (1) {
    int n;
    cin >> n;
    if (n == 0) break;
    int* dataarray = new int[n];
    for (int i = 0; i < n; i++) {
      cin >> dataarray[i];
    }
    for (int i = 0; i < n; i++) {
      if (map.find(dataarray[i]) == map.end()) {
        map[dataarray[i]] = 1;
      } else {
        map[dataarray[i]]++;
      }
    }
    // cout <<"=============="<< endl;
    int max = 0;
    int max_key = 0;
    for (auto it = map.begin(); it != map.end(); it++) {
      // cout << it->first << " " << it->second<< endl;
      if (it->second > max) {
        max = it->second;
        max_key = it->first;
      }
    }
    cout << max_key << endl;
    map.clear();
  }
}