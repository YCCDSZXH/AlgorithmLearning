#include <iostream>
using namespace std;
void step_forward(int& local, int& local2, const int& step, const int& n) {
  local += step;
  if (local > n - 1) local = 2 * (n - 1) - local;
  if (local2 == local) local2 = 0;
}

int main() {
  int A, B, C, N;
  while (cin >> N >> A >> B >> C) {
    string status[N];
    for (int i = 0; i < N; i++) {
      cin >> status[i];
    }
    int step = C;
    bool whos_turn = 1;
    int local_A = 0;
    int local_B = 0;
    while (local_A != N-1 && local_B != N-1) {
      step = (A * step + B) % 6 + 1;
      if (whos_turn) {
        step_forward(local_A, local_B, step, N);
        while (status[local_A][0] != 'N') {
          // step_forward(local_A, local_B, status[local_A][1] - 48, N);
          local_A = status[local_A][1] - 48;
        }
      } else {
        step_forward(local_B, local_A, step, N);
        while (status[local_B][0] != 'N') {
          // step_forward(local_B, local_A, status[local_B][1] - 48, N);
          local_B = status[local_B][1] - 48;
        }
      }
      whos_turn = !whos_turn;
    }
    if (local_A == N-1) {
      cout << "Lele" << endl;
    }
    if (local_B == N-1) {
      cout << "Yueyue" << endl;
    }
  }
}