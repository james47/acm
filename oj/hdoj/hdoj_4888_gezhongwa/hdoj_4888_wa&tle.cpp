#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

int n, m, k, st, ed, esize, w, maxflow;
int matrix[500][500];
int lv[1000], en[1000];
bool vis[1000];
struct Edge{
	int v, w, n;
	Edge(){}
	Edge(int v, int w, int n): v(v), w(w), n(n){}
} e[600000];
void addedge(int u, int v, int w)
{
	e[esize] = Edge(v, w, en[u]);
	en[u] = esize ++;
	e[esize] = Edge(u, 0, en[v]);
	en[v] = esize ++;
}
bool bfs(int st, int ed)
{
	memset(lv, -1, sizeof(lv));
	lv[st] = 0;
	queue<int> Q;
	while(!Q.empty()) Q.pop();
	Q.push(st);
	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();
		for (int t = en[u]; t != -1; t = e[t].n){
			int v = e[t].v;
			if (lv[v] == -1 && e[t].w > 0){
				lv[v] = lv[u] + 1;
				if (v != ed) Q.push(v);
			}
		}
	}
	return lv[ed] > -1; 
}
int dfs(int u, int v, int flow)
{
	if (flow == 0) return 0;
	if (u == ed) return flow;
	int nflow = 0, nn;
	for (int t = en[u]; t != -1; t = e[t].n){
		int v = e[t].v;
		if (lv[v] == lv[u] + 1){
			nn = dfs(v, ed, min(flow-nflow, e[t].w));
			e[t].w -= nn;
			nflow += nn;
			e[t^1].w += nn;
		}
	}
	return nflow;
}
bool findloop(int u, int dep, int fa)
{
	if (vis[u] && dep > 2) return true;
	vis[u] = true;
	for (int t = en[u]; t != -1; t = e[t].n){
		int v = e[t].v;
	//	if (vis[v] && v != fa) return true;
		if (e[t].w <= 0 || v == fa || v == st || v == ed) continue;
		if (findloop(v, dep+1, u)) return true; 
	}
	return false;
}
bool find()
{
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i++){
		if (vis[i]) continue;
		if (findloop(i, 0, st))
			return true;
	}
	return false;
}
int main()
{
	while(scanf("%d%d%d", &n, &m, &k) != EOF)
	{
		memset(en, -1, sizeof(en));
		esize = 0;
		st = 0, ed = n + m + 1;
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
		while(bfs(st, ed)){
			maxflow += dfs(st, ed, 7000000);
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
