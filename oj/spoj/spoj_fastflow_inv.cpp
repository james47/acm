#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const long long inf = (long long)1e17 + 10;
struct edge{
	int v, w, n;
} e[60200];
int en[5010], lv[5010], q[5010], cur[5010];
int n, m, sou, tar, esize;
void addedge(int u, int v, int w){
	e[esize].v = v;
	e[esize].w = w;
	e[esize].n = en[u];
	en[u] = esize ++;
}
bool bfs()
{
	memset(lv, -1, sizeof(lv));
	int head, tail;
	lv[sou] = head = tail = 0;
	q[tail++] = sou;
	while(head < tail){
		int u = q[head++];
		for (int t = en[u]; t != -1; t = e[t].n){
			int v = e[t].v;
			if (lv[v] == -1 && e[t].w > 0){
				lv[v] = lv[u] + 1;
				if (v != tar) q[tail++] = v;
			}
		}
	}
	return lv[tar] != -1;
}
long long dfs(int u, long long maxf)
{
	if (maxf == 0) return 0;
	if (u == tar) return maxf;
	long long ret = 0, res, flow;
	for (int &t = cur[u]; t != -1; t = e[t].n){
		int v = e[t].v;
		if (e[t].w > 0 && lv[v] == lv[u] + 1){
			//res = min(maxf - ret, e[t].w);
			res = maxf - ret;
			if (e[t].w < res) res = e[t].w;
			flow = dfs(v, res);
			if (flow > 0){
				e[t].w -= flow;
				e[t^1].w += flow;
				ret += flow;
				if (maxf == ret) return ret;
			}
			//else lv[v] = -1;
		}
	}
	return ret;
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		int x, y, z;
		sou = 1, tar = n;
		esize = 0;
		memset(en, -1, sizeof(en));
		for (int i = 0; i < m; i++){
			scanf("%d %d %d", &x, &y, &z);
			addedge(x, y, z);
			addedge(y, x, z);
		}
		//dinic();
		long long maxflow = 0;
		while(bfs()){
			for (int i = 1; i <= n; i++) cur[i] = en[i];
			maxflow = maxflow + dfs(sou, inf);
		}
		printf("%lld\n", maxflow);
	}
	return 0;
}
