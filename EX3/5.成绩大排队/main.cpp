#include <iostream>
#include <map>
using namespace std;
int main() {
  int n;
  cin >> n;
  int tmp;
  string name, id;
  map<int, string[2]> m;
  for (int i = 0; i < n; i++) {
    cin >> name >> id >> tmp;
    m[tmp][0] = name;
    m[tmp][1] = id;
  }
  // for (auto i : m) {
  //   cout << i.second[0] << " " << i.second[1] << endl;
  // }
  // for(auto m_it = m.begin(); m_it != m.end(); m_it++){
  //   cout << m_it->second[0] << " " << m_it->second[1] << endl;
  // }
  auto m_it = m.end();
  m_it--;
  cout << m_it->second[0] << " " << m_it->second[1] << endl;
  m_it = m.begin();
  cout << m_it->second[0] << " " << m_it->second[1] << endl;
}