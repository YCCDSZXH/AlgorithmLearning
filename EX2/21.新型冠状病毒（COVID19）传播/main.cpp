#include <algorithm>
#include <iostream>
using namespace std;

struct people {
  int num;  //储存输入的顺序，方便在遍历时找到零号感染者
  int pos;  //位置
  int v;    //速度
};

bool cmp(const people &l, const people &r) {
  if (l.pos == r.pos) {
    return l.v > r.v;
  }
  return l.pos < r.pos;
}

const int N = 10000500;
//发现如果N开成10000010会爆内存
//所以N开大点
people p[N];

int main() {
  int n, s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> p[i].pos;
  for (int i = 0; i < n; i++) {
    p[i].num = i + 1;  //初始化编号
    cin >> p[i].v;
  }
  sort(p, p + n, cmp);
  int lmaxv = -1;
  int mid;
  for (mid = 0; mid < n; mid++) {
    if (p[mid].v > lmaxv) lmaxv = p[mid].v;
    if (p[mid].num == s) break;
  }
  int safe = 0;         //储存未感染人数
  int rminv = 1000000;  //初始化
  for (int i = mid; i < n; i++) {
    if (p[i].v >= lmaxv && p[i].pos > p[mid].pos) safe++;

    if (p[i].v < rminv) rminv = p[i].v;

  }
  for (int i = 0; i < mid; i++) {
    if (p[i].v <= rminv && p[i].pos < p[mid].pos) safe++;

  }
  cout << n - safe << endl;
  //输出总人数减去安全人数
  system("pause");
  return 0;
}