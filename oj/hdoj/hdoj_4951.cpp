#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int p, cas = 0;
int a[510][510], b[510][510];
int ans[510];
bool v[510];
int read()
{
	int ret = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret;
}
//
//int read()
//{
//	int ret = 0;
//	bool flag = 0;
//	char ch;
//	while(1){
//		ch = getchar();
//		if (ch >= '0' && ch <= '9') {flag = 1; ret = ret*10 + ch-'0';}
//		else if (flag) return ret;
//	}
//}
int find0()
{
	for (int i = 0; i < p; i++){
		bool flag = true;
		int x = a[i][0];
		for (int j = 0; j < p; j++)
			if (x != a[i][j] || x != b[i][j] || x != a[j][i] || x != b[j][i]) {flag = 0; break;}
		if (flag) return i;
	}	
}
int find1()
{
	for (int i = 0; i < p; i++){
		if (a[i][i] == ans[0] && b[i][i] == i) return i;
	}
}
int main()
{
	while(scanf("%d", &p))
	{
		if (p == 0) break;
		for (int i = 0; i < p; i++)
			for (int j = 0; j < p; j++){
				//scanf("%d %d", &a[i][j], &b[i][j]);
				a[i][j] = read();b[i][j] = read();
			}
		ans[0] = find0();
		ans[1] = find1();
		for (int i = 0; i < p; i++)
			if (i != ans[0] && i != ans[1]){
				memset(v, 0, sizeof(v));
				for (int j = 0; j < p; j++) v[a[i][j]] = true;
				int cnt = 0;
				for (int j = 0; j < p; j++) if (v[j]) cnt++;
				ans[cnt] = i;
			}
		printf("Case #%d: ", ++cas);
		for (int i = 0; i < p; i++)
			printf("%d%c", ans[i], i==p-1?'\n':' ');
	}
	return 0;
}
