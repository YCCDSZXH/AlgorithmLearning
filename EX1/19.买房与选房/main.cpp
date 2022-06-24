#include <iostream>

using namespace std;

struct people

{
  char id[19]; /* 身份证号码 */

  int social; /* 社保缴纳月数 */

  int area; /* 现有住房面积 */

  char date[11]; /* 申报日期 */
};

people *getMess(int &n);
bool cmp1(people a, people b);
bool cmp2(people a, people b);

int main()

{
  people *person; /* 指向所有报名人的基本资料首地址，通过调用函数getMess获取 */

  int n; /* n为报名人数，通过调用函数getMess获取 */

  person = getMess(n);

  // ...
  int index = 0;
  people *p = new people;
  for (int i = 0; i < n; i++) {
    // person[i].date = ;
    string tmp;
    tmp = person[i].date;
    person[i].date[0] = tmp[6];
    person[i].date[1] = tmp[7];
    person[i].date[2] = tmp[8];
    person[i].date[3] = tmp[9];
    person[i].date[4] = tmp[3];
    person[i].date[5] = tmp[4];
    person[i].date[6] = tmp[0];
    person[i].date[7] = tmp[1];
    person[i].date[8] = '\0';
    person[i].date[9] = '\0';
    if (person[i].social >= 24 && person[i].area == 0) {
      // p = &person[i];
      // person[i] = person[index];
      // person[index] = *p;
      // index++;
      swap(person[i], person[index]);
      index++;
    }
    // cout << person[i].id << " " << person[i].social << " " << person[i].area
    //      << " " << person[i].date << endl;
  }
  sort(person, person + index, cmp1);
  sort(person + index, person + n, cmp2);
  for (int i = 0; i < n; i++) {
    cout << person[i].id << " " << person[i].social << " " << person[i].area
         << " " << person[i].date << endl;
  }
  //
  int numb, max;
  cin >> numb >> max;
  for (int i = 0; i < numb; i++) {
    string tmp;
    cin >> tmp;
    int sum = 0;
    for (int j = 0; j < n; j++) {
      if (tmp == person[j].id) {
        if (j < max) {
          for (int k = j; k < n; k++) {
            if (k > index) {
              if (person[k].date == person[k + 1].date) {
                sum++;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
bool cmp1(people a, people b) {
  if (a.social > b.social)
    return true;
  else if (a.social == b.social) {
    if (strcmp(a.date, b.date) > 0)
      return true;
    else
      return false;
  } else
    return false;
}

bool cmp2(people a, people b) {
  if (a.area < b.area)
    return true;
  else if (a.area == b.area) {
    if (strcmp(a.date, b.date) < 0)
      return true;
    else
      return false;
  } else
    return false;
}

people *getMess(int &n) /* 将文件数据读入内存 */

{
  FILE *fp;

  fp = fopen("EX1/19.买房与选房/house.bin", "rb");

  fseek(fp, -1 * (long)sizeof(int), 2);

  fread(&n, sizeof(int), 1, fp);

  rewind(fp);

  people *tmp = new people[n];

  fread(tmp, sizeof(people), n, fp);

  fclose(fp);

  return tmp;
}