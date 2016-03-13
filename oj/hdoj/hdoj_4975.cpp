//能过本题，但是找环方法有误，标记为2的点有可能是环上的点。
/*
1
2 3
16 21
18 13 6
可以填
9 6 1
9 7 5
应为多解。
*/
#include<stdio.h>
#include<string.h>

int n, m, k, st, ed, esize, w, maxflow, cas;
int matrix[600][600];
int lv[1200], en[1200], q[1200], cur[1200];
int vis[600000];
int vv[1200];
struct Edge{
	int v, w, n;
} e[600000];
void addedge(int u, int v, int w)
{
	e[esize].v = v; e[esize].w = w; e[esize].n = en[u];
	en[u] = esize ++;
	e[esize].v = u; e[esize].w = 0; e[esize].n = en[v];
	en[v] = esize ++;
}
bool bfs()
{
	memset(lv, -1, sizeof(lv));
	int head, tail;
	lv[st] = head = tail = 0;
	q[tail++] = st;
	while(head < tail)
	{
		int u = q[head++];
		for (int t = en[u]; t != -1; t = e[t].n){
			int v = e[t].v;
			if (lv[v] == -1 && e[t].w > 0){
				lv[v] = lv[u] + 1;
				q[tail++] = v;
				if (v == ed) return 1;
			}
		}
	}
	return 0;
}
int dfs(int u, int maxf)
{
	if (maxf == 0) return 0;
	if (u == ed) return maxf;
	int ans = 0, flow, tmp;
	for (int &t = cur[u]; t != -1; t = e[t].n){
		int v = e[t].v;
		if (e[t].w > 0 && lv[v] == lv[u] + 1){
			tmp = maxf - ans;
			if (e[t].w < tmp) tmp = e[t].w;
			flow = dfs(v, tmp);
			if (flow > 0){
				e[t].w -= flow;
				ans += flow;
				e[t^1].w += flow;
				if (maxf == ans) return ans;
			}
			else lv[v] = -10;
		}
	}
	lv[u] = -10;
	return ans;
}
bool findloop(int u, int fa)
{
	if (vv[u] == 1) return true;
	if (vv[u] == 2) return false;
	vv[u] = 1;
	for (int t = en[u]; t != -1; t = e[t].n){
		int v = e[t].v;
		if (e[t].w <= 0 || v == fa || v == st || v == ed) continue;
		if (vis[t] == cas) continue;
		vis[t] = cas;
		if (findloop(v, u)) return true; 
	}
	vv[u] = 2;
	return false;
}
bool find()
{
	memset(vv, 0, sizeof(vv));
	for (int i = 1; i <= n; i++){
		if (!vv[i] && findloop(i, st)) return true;
	}
	return false;
}
int T;
int main()
{
	memset(vis, 0, sizeof(vis));
	cas = 0; k = 9;
	scanf("%d", &T);
	while(T--)
	{
		printf("Case #%d: ", ++cas);
		scanf("%d%d", &n, &m);
		memset(en, -1, sizeof(en));
		esize = 0;
		st = n+m+1, ed = n+m+2;
		int sumr = 0, sumc = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d", &w);
			addedge(st, i, w);
			sumr += w;
		}
		for (int j = n+1; j <= n+m; j++){
			scanf("%d", &w);
			addedge(j, ed, w);
			sumc += w;
		}
		if (sumr != sumc){
			printf("So naive!\n");
			continue;
		}
		if (sumr == 0){
			printf("So simple!\n");
			continue;
		}
		for (int i = 1; i <= n; i++)
			for (int j = n+1; j <= n+m; j++)
				addedge(i, j, k);
		maxflow = 0;
		while(bfs()){
			for (int i = 1; i <= n+m+2; i++) cur[i] = en[i];
			maxflow += dfs(st, 7000000);
		}
		if (maxflow == sumr){
			if (find())
				printf("So young!\n");
			else{
				printf("So simple!\n");
			}
		}
		else{
			printf("So naive!\n");
			continue;
		}
	}
	return 0;
}
