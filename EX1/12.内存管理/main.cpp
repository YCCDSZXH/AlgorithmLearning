// #include <iostream>
// #include <map>
// using namespace std;
// int main() {
//   map<int, int> m;
//   int task, n;
//   cin >> task >> n;
//   // cout << task << " " << n << endl;
//   int numb[task];
//   int endsize = n;
//   string task_name[task];
//   for (int i = 0; i < task; i++) {
//     cin >> task_name[i];
//     if (task_name[i][0] != 'd') {
//       cin >> numb[i];
//     }
//   }
//   // for(int i = 0; i < task; i++) {
//   //   cout << task_name[i] << ' ' << numb[i]<< endl;
//   // }
//   int count = 1;
//   for (int i = 0; i < task; i++) {
//     switch (task_name[i][0]) {
//       case 'a':
//         if (endsize >= numb[i]) {
//           m[count] = numb[i];
//           cout << count << endl;
//           count++;
//           endsize -= numb[i];
//         }else{
//           cout << "NULL" << endl;
//         }
//         break;
//       case 'e':
//         if (m.find(count-1) != m.end()) {
//           endsize += m[count-1];
//         }

//         if (m.find(numb[i]) != m.end()) {
//           m.erase(numb[i]);
//         } else {
//           cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
//         }

//         break;
//       case 'd':
//         endsize = n;
//         for (auto it = m.begin(); it != m.end(); it++) {
//           endsize -= it->second;
//         }
//         break;
//     }
//   }
// }

// // 14 100
// // alloc 99  1
// // alloc 1   2
// // alloc 1   null
// // erase 2   
// // alloc 1   3
// // erase 4   iiii
// // erase 1   
// // alloc 100 null
// // alloc 1   4
// // alloc 99
// // defragment 
// // erase 4
// // alloc 100
// // alloc 99
#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
int n,m,num=0;
int a[100009],b[100009],d[100009];
pii c[509];
bool vis[509];
int main(){
	scanf("%d%d",&n,&m);
	for(int o=1;o<=n;++o){
		char C[19];int len,x;
		scanf("%s",C);
		if(C[0]=='a'){
			scanf("%d",&len);
			bool bol=0;
			for(int i=1;i<=m-len+1;++i){
				if(a[i]==0&&b[i+len-1]-b[i-1]==0){
				//	cout<<i<<" "<<i+len-1<<endl;
					c[++num]=mk(i,i+len-1);
					for(int j=i;j<=i+len-1;++j)a[j]=1,d[j]=num;
					printf("%d\n",num);
					bol=1;
					break;
				}
			}
			if(!bol)puts("NULL");
		}
		if(C[0]=='e'){
			scanf("%d",&x);
			if(x>num||x<1||vis[x])puts("ILLEGAL_ERASE_ARGUMENT");
			else {
				vis[x]=1;
				for(int i=c[x].fi;i<=c[x].se;++i)a[i]=0,d[i]=0;
			}
		}
		if(C[0]=='d'){
			for(int i=1,la=0;i<=m;++i){
				if(!a[i]&&!la)la=i;
				if(a[i]&&la){
					int x=d[i],len=c[x].se-c[x].fi+1;
					for(int j=c[x].fi;j<=c[x].se;++j)a[j]=d[j]=0;
					for(int j=la;j<=la+len-1;++j)a[j]=1,d[j]=x;
					la=0;
				}
			}
		}
		for(int i=1;i<=m;++i)b[i]=b[i-1]+a[i];
	}
	return 0;
}