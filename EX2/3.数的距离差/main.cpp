#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long tmp = 0;
  vector <pair<long long,long long>> v;
  for (long long i = 0; i < n; i++) {
    cin >> tmp;
    v.push_back(make_pair(tmp,0));
  }
  sort(v.begin(), v.end(), [](const pair<long long,long long> &a, const pair<long long,long long> &b) {
    return a.first < b.first;
  });
  long long max_min = v[0].first + v[n - 1].first;
  for (long long i = 0; i < n; i++) {
      v[i].second += abs(max_min - 2*v[i].first);
  }
  sort(v.begin(), v.end(), [](const pair<long long,long long> &a, const pair<long long,long long> &b) {
    return a.second < b.second;
  });
  cout << v[0].first << endl;
}