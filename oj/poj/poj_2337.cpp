#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct edge{
	int from, to, u;
	char str[50];
	bool operator < (const edge a) const{
		return strcmp(str, a.str) < 0;
	}
} e[2000];
int n, cnt, ru[30], ch[30], f[30];
char ans[1500][50];
bool c[30];
int getf(int x)
{
	if (x == f[x]) return x;
	f[x] = getf(f[x]);
	return f[x];
}
void unionxy(int x, int y)
{
	int xroot = getf(x),
	    yroot = getf(y);
	f[xroot] = yroot;
}
void dfs(int st)
{
	for (int i = 0; i < n; i ++){
		if (e[i].from == st && !e[i].u){
			e[i].u = true;
			dfs(e[i].to);
			strcpy(ans[cnt], e[i].str);
			cnt++;
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		memset(c, 0, sizeof(c));
		memset(ru, 0, sizeof(ru));
		memset(ch, 0, sizeof(ch));
		for (int i = 0; i < 26; i++)
			f[i] = i;
		for (int i = 0; i < n; i++){
			scanf("%s", e[i].str);
			int x = e[i].str[0] - 'a',
			    y = e[i].str[strlen(e[i].str)-1] - 'a';
			e[i].from = x;
			e[i].to = y;
			e[i].u = false;
			ch[x]++; ru[y]++;
			c[x] = true; c[y] = true;
			unionxy(x, y);
		}
		cnt = 0;
		for (int i = 0 ; i < 26; i++)
			if (c[i] && f[i] == i) cnt ++;
		if (cnt > 1){
			puts("***");
			continue;
		}
		sort(e, e+n);
		/*wa
		int st = 0;
		for (int i = 25; i >= 0; i--)
			if (c[i] && ch[i] - ru[i] == 1) st = i;
		cnt = 0;
		*/
		int flag1 = 0, flag2 = 0, key = 0;
		int st, ed;
		for (int t = 25; t >= 0; t--){
			if (ch[t] == ru[t] + 1){
				st = t;
				flag1++;
			}
			else if (ru[t] == ch[t]+1){
				ed = t;
				flag2++;
			}
			else if (ru[t] == ch[t]){
				if (ch[t] != 0 and flag1 == 0){
					st = t, ed = t;
				}
			}
			else key = 1;
		}
		if (flag1 > 1 or flag2 > 1)
			key = 1;
		else if (flag1 != flag2)
			key = 1;
		if (key == 1){
			printf("***\n");
			continue;
		}

		cnt = 0;
		dfs(st);
		if (cnt < n) 
			puts("***");
		else{
			for (int i = n-1; i > 0; i--)
				printf("%s.", ans[i]);
			printf("%s\n", ans[0]);
		}
	}
	return 0;
}
