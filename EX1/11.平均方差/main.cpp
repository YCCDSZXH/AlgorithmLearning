#include <iostream>
// #include <map>
using namespace std;
int main(){
  int n;
  cin >> n;
  while(n){
    double * data = new double[n];
    for(int i = 0; i < n; i++){
      cin >> data[i];
    }
    double sum = 0;
    for(int i = 0; i < n; i++){
      sum += data[i];
    }
    double avg = sum / n;
    double res = 0;
    for(int i = 0; i < n; i++){
      res += (data[i] - avg) * (data[i] - avg);
    }
    cout << int(res / n) << endl;
    cin >> n;
  }
}