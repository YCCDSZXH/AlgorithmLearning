#include <iostream>
#include <vector>
using namespace std;
void print_res(vector<string> &v1, vector<string> &v2) {
  int score_numb = v1.size();
  for (int i = 0; i < score_numb; i++) {
    cout << i + 1 << ' ';
  }
  cout << "Score" << endl;
  int score = 0;
  for (auto it = v1.begin(); it != v1.end(); it++) {
    if (it->find(" no good") == string::npos) {
      cout << 'O' << " ";
      score++;
    } else {
      cout << 'X' << " ";
    }
  }
  cout << score << endl;
  score = 0;
  for (auto it = v2.begin(); it != v2.end(); it++) {
    if (it->find(" no good") == string::npos) {
      cout << 'O' << " ";
      score++;
    } else {
      cout << 'X' << " ";
    }
  }
  if (v2.size() < v1.size()) cout << "- ";
  cout << score << endl;
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
    print_res(v[0], v[1]);
    cin >> n;
    getchar();
  }
}