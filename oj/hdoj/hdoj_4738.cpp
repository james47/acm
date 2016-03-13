#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int inf = 2147483647;
int esize, n, m, dtime, ans;
int low[1010], dfn[1010], en[1010], f[1010];
struct edge{
	int v, n, w;
	bool u;
} e[2002000];
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
void insert(int u, int v, int w){
	e[esize].v = v;
	e[esize].n = en[u];
	e[esize].w = w;
	e[esize].u = false;
	en[u] = esize ++;
}
void dfs(int u)
{
	low[u] = dfn[u] = dtime ++;
	for (int t = en[u]; t != -1; t = e[t].n){
		if (e[t^1].u) continue;
		e[t].u = true;
		int v = e[t].v;
		if (!dfn[v]){
			dfs(v);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u]){
				if (e[t].w == 0)
					ans = min(ans, 1);
				else
					ans = min(ans, e[t].w);
			}
		}
		else
			low[u] = min(low[u], dfn[v]);
	}
}
int main()
{
	while(scanf("%d %d", &n, &m) && (n + m))
	{
		memset(en, -1, sizeof(en));
		esize = 0;
		for (int i = 1; i <= n; i++)
			f[i] = i;
		int x, y, w;
		for (int i = 0; i < m; i++){
			scanf("%d %d %d", &x, &y, &w);
			insert(x, y, w);
			insert(y, x, w);
			unionxy(x, y);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (f[i] == i) cnt ++;
		if (cnt > 1){
			puts("0");
			continue;
		}
		memset(dfn, 0, sizeof(dfn));
		dtime = 1, ans = inf;
		for (int i = 1; i <= n; i++)
			if (!dfn[i]) dfs(i);
		if (ans == inf) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}
