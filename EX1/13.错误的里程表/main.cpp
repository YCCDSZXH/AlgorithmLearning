#include<iostream>
using namespace std;
long long eight2ten(long long A){
  long long res = 0;
  long long tmp = 1;
  // res += 
  while(A){
    long long tmp2 = A % 10;
    if(tmp2 > 8){
      tmp2 -= 2;
    }else if(tmp2>3){
      tmp2 -= 1;
    }
    res += tmp2 * tmp;
    tmp*=8;
    A/=10;
  }
  return res;
}
int main(){
  long long n; 
  cin >> n;
  long long numb;
  for (long long i = 0;i < n;i++){
    cin >> numb;
    cout << eight2ten(numb) << endl;
  }
}
