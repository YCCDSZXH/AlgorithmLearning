#include <iostream>

using namespace std;

int a[1000][1000];

int c;
int dire;
int x, y;
int n;
int i, j;

void move() {
  switch (dire) {
    case 0:
      x++;
      return;

    case 1:
      y++;
      return;

    case 2:
      x--;
      return;

    case 3:
      y--;
      return;
  }
}

int main() {
  cin >> n;

  x = (n - 1) / 2;
  y = x;

  c = 1;
  a[y][x] = c;
  c++;

  dire = 0;

  move();

  a[y][x] = c;
  c++;
  dire = (dire + 1) % 4;

  for (i = 1; i < n; i++) {
    for (j = 0; j < i; j++) {
      move();
      a[y][x] = c;
      c++;
    }
    dire = (dire + 1) % 4;

    for (j = 0; j < i; j++) {
      move();
      a[y][x] = c;
      c++;
    }
    move();
    a[y][x] = c;
    c++;
    dire = (dire + 1) % 4;
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}
