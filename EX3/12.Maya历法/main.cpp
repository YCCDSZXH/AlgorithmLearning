#include <iostream>
#include <string>
using namespace std;
string month[19] = {"pop",  "no",   "zip",   "zotz",  "tzec", "xul", "yoxkin",
                    "mol",  "chen", "yax",   "zac",   "ceh",  "mac", "kankin",
                    "muan", "pax",  "koyab", "cumhu", "uayet"};
string day[20] = {"imix",  "ik",    "akbal", "kan",   "chicchan",
                  "cimi",  "manik", "lamat", "muluk", "ok",
                  "chuen", "eb",    "ben",   "ix",    "mem",
                  "cib",   "caban", "eznab", "canac", "ahau"};
int find_month(string mon) {
  for (int i = 0; i < 19; i++) {
    if (month[i] == mon) {
      return i;
    }
  }
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    int Haab_day, Haab_year;
    char point;  //这样避免了字符串的处理
    string Haab_month;
    cin >> Haab_day >> point >> Haab_month >> Haab_year;
    int totol_day = Haab_year * 365 + find_month(Haab_month) * 20 +
                    Haab_day;  //计算出总的天数
    int Tzolkin_num, Tzolkin_year;
    string Tzolkin_day;
    Tzolkin_year = totol_day / 260;
    totol_day %= 260;
    Tzolkin_num = totol_day % 13 + 1;
    Tzolkin_day = day[totol_day % 20];
    cout << Tzolkin_num << " " << Tzolkin_day << " " << Tzolkin_year << endl;
  }
  return 0;
}