#include <iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  string str[n];
  getchar();
  for(int i = 0; i < n;i++){
    getline(cin,str[i]);
    // cout << str[i] << endl;
  }
  for(int i = 0;i < n;i++){
  int index = 0;
    for(int j = 0; j < str[i].length();j++){
      if(str[i][j] == ' '){
        for(int k = j-1;k>=index;k--){
          cout << str[i][k];
        }
        cout << ' ';
        index = j+1;
      }
      else if(j == str[i].length()-1){
        for(int k = j;k>=index;k--){
          cout << str[i][k];
        }
        // cout << '*';
        index = j;
      }
    }
    cout << endl;
  }
}