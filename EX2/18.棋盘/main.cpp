#include <cstring>
#include <iostream>
using namespace std;
bool map[2001][2001];
int N, num[2001], ans = 0;
void dfs(int m, int n,
         int depth)
{
  if (map[m][n] == 0) return;  //左上角的顶点为白色，返回
  if (m + depth - 1 > N || n + depth - 1 > N)
    return;  //行或列超过给定矩阵的范围，返回
  for (int i = 1; i <= depth; i++) {
    for (int j = 1; j <= depth;
         j++) {  //行号和列号之和为偶数，该点却是白色，返回
      if ((i + j) % 2 == 0 && map[m + i - 1][n + j - 1] == 0) return;
      //行号和列号之和为奇数 ，该点却是黑色，返回
      else if ((i + j) % 2 == 1 && map[m + i - 1][n + j - 1] == 1)
        return;
    }
  }
  //进行到这一步说明以map[m][n]左上角的顶点，depth为尺寸的棋盘是存在的
  if (depth > ans) ans = depth;  //更新最大尺寸
  num[depth]++;                  //将该尺寸的数目加一
  dfs(m, n, ++depth);  //尺寸扩大一，仍以该点为左上角的顶点深搜
}
int main() {
  cin >> N;
  string tmp;
  for (int i = 1; i <= N; i++) {
    cin >> tmp;
    for (int j = 1; j <= N; j++) map[i][j] = tmp[j - 1] - 48;
  }

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) dfs(i, j, 1);

  cout << ans << ' ' << num[ans];
}
