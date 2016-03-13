#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int en[10010], col[10010], dfn[10010], low[10010], stack[10010], tot[10010], chu[10010];
bool ins[10010];
int n, m, esize, dtime, stop, scc;
struct edge{
	int v, n;
} e[50010];
void insert(int u, int v)
{
	e[esize].v = v;
	e[esize].n = en[u];
	en[u] = esize ++;
}
void dfs(int x)
{
	dfn[x] = low[x] = dtime ++;
	stack[stop++] = x;
	ins[x] = true;
	for (int t = en[x]; t != -1; t = e[t].n){
		int v = e[t].v;
		if (!dfn[v]){
			dfs(v);
			low[x] = min(low[x], low[v]);
		}
		else if (ins[v]){
			low[x] = min(low[x], dfn[v]);
		}
	}
	if (dfn[x] == low[x]){
		scc ++;
		while(stack[--stop] != x){
			col[stack[stop]] = scc;
			ins[stack[stop]] = false;
		}
		col[x] = scc;
		ins[x] = false;
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	int a, b;
	esize = 0;
	memset(en, -1, sizeof(en));
	for (int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		insert(a, b);
	}
	memset(dfn, 0, sizeof(dfn));
	memset(col, 0, sizeof(col));
	memset(ins, 0, sizeof(ins));
	dtime = 1; stop = 0; scc = 0;
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) dfs(i);
	memset(chu, 0, sizeof(chu));
	memset(tot, 0, sizeof(tot));
	for (int i = 1; i <= n; i++){
		int u = col[i];
		tot[u]++;
		for (int t = en[i]; t != -1; t = e[t].n){
			int v = col[e[t].v];
			if (u != v)
				chu[u] ++;
		}
	}
	int cnt = 0, ans;
	for (int i = 1; i <= scc; i++)
		if (chu[i] == 0){
			cnt ++;
			ans = tot[i];
		}
	if (cnt > 1) ans = 0;
	printf("%d\n", ans);
	return 0;
}
