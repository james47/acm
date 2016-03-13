#include<stdio.h>
#include<string.h>

int n, m, k, st, ed, esize, w, maxflow, cas;
int matrix[500][500];
int lv[1000], en[1000], q[1000], cur[1000];
int vis[600000];
bool vv[1000];
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
	for (int t = en[u]; t != -1; t = e[t].n){
		int v = e[t].v;
		if (e[t].w <= 0 || v == fa || v == st || v == ed) continue;
		if (vv[v]) return true;
		if (vis[t] == cas) continue;
		vis[t] = cas;
		vv[v] = true;
		if (findloop(v, u)) return true; 
		vv[v] = false;
	}
	return false;
}
bool find()
{
	memset(vv, false, sizeof(vv));
	for (int i = 1; i <= n; i++){
		vv[i] = true;
		if (findloop(i, st)) return true;
		vv[i] = false;
	}
	return false;
}
int main()
{
	memset(vis, 0, sizeof(vis));
	cas = 0;
	while(scanf("%d%d%d", &n, &m, &k) != EOF)
	{
		cas ++;
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
			printf("Impossible\n");
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
				printf("Not Unique\n");
			else{
				printf("Unique\n");
				for (int u = 1; u <= n; u++){
					for (int t = en[u]; t != -1; t = e[t].n){
						int v = e[t].v;
						if (v > n)
							matrix[u][v-n] = k-e[t].w;
					}
				}
				for (int i = 1; i <= n; i++){
					for (int j = 1; j < m; j++)
						printf("%d ", matrix[i][j]);
					printf("%d\n", matrix[i][m]);
				}
			}
		}
		else{
			printf("Impossible\n");
			continue;
		}
	}
	return 0;
}
