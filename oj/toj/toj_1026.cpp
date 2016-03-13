#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int esize, n, root, dtime;
struct edge{
	int v, n;
} e[100000];
int en[200], dfn[200], low[200];
bool cut[200];
int min(int a, int b)
{
	if (a < b) return a; else return b;
}
void insert(int u, int v)
{
	e[esize].v = v;
	e[esize].n = en[u];
	en[u] = esize++;
}
void dfs(int x, int fa)
{
	int son = 0;
	dfn[x] = low[x] = dtime++;
	for (int t = en[x]; t != -1; t = e[t].n){
		int v = e[t].v;
		if (v == fa) continue;
		if (!dfn[v]){
			son++;
			dfs(v, x);
			low[x] = min(low[x], low[v]);
			if ((x != root && low[v] >= dfn[x]) || (x == root && son > 1))
				cut[x] = true;
		}
		else{
			low[x] = min(low[x], dfn[v]);
		}
	}
}
int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		memset(en, -1, sizeof(en));
		int x, y, esize = 0;
		char ch;
		while(scanf("%d", &x) == 1 && x){
			while((ch = getchar()) != '\n'){
				scanf("%d", &y);
				insert(x, y);
				insert(y, x);
			}
		}
		memset(dfn, 0, sizeof(dfn));
		memset(cut, 0, sizeof(cut));
		root = 1; dtime = 1;
		dfs(1, 0);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (cut[i]) {
				ans++;
			}
		printf("%d\n", ans);
	}
	return 0;
}
