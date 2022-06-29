#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  int tmp1,tmp2;
  map<int,int> m;
  for(int i=0;i<n;i++){
    cin >> tmp1 >> tmp2;
    m[tmp1] += tmp2;
  }
  vector<pair<int,int>> v;
  for(auto it=m.begin();it!=m.end();it++){
    v.push_back(make_pair(it->first,it->second));
  }
  sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){
    return a.second>b.second;
  });
  cout << v[0].first << ' ' << v[0].second << endl;
}