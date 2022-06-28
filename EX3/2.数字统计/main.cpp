#include <iostream>
#include <map>
using namespace std;
int main(){
  map<char,int> m;
  string str;
  cin >> str;
  for(int i = 0; i < str.length();i++){
    m[str[i]]++;
  }
  for(auto i : m){
    cout << i.first << ":" << i.second << endl;
  }
}