#include <bits/stdc++.h>
using namespace std;

void getpost(string preorder, string inorder)  //根据先序和中序求后序
{
  int n = preorder.length();  // n为每次遍历数目
  if (n > 0) {
    char root = preorder[0];     //根结点为先序遍历的第一个
    int i = inorder.find(root);  //中序遍历中根结点的所在下标
    getpost(preorder.substr(1, i), inorder.substr(0, i));    //左子树
    getpost(preorder.substr(i + 1), inorder.substr(i + 1));  //右子树
    cout << root;
  }
}

int main() {
  string preorder, inorder;  //先序遍历和中序遍历
  int n;
  cin >> n;
  while (n) {
    cin >> preorder >> inorder;
    getpost(preorder, inorder);
    cout << endl;
    cin >> n;
  }
  return 0;
}