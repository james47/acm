#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const long long inf = (long long)1e17 + 10;
int n, m, w, esize = 0, x, y;
int en[5010], lv[5010], Q[5010];
int qh, qt;
struct Edge{
	int v, w, n;
}e[60200];
void addedge(int u, int v, int w)
{
	e[esize].v = v;
	e[esize].w = w;
	e[esize].n = en[u];
	en[u] = esize ++;
	e[esize].v = u;
	e[esize].w = w;
	e[esize].n = en[v];
	en[v] = esize ++;
}
bool bfs()
{
	memset(lv, -1, sizeof(lv));
	lv[n] = qh = qt = 0;
	Q[qt++] = n;
	while(qh < qt)
	{
		int u = Q[qh++];
		for (int t = en[u]; t != -1; t = e[t].n){
			int v = e[t].v;
			if (lv[v] == -1 && e[t^1].w > 0){
				lv[v] = lv[u] + 1;
				if (v != 1){
					Q[qt++] = v;
				}
			}
		}
	}
	return lv[1] > -1;
}
long long dfs(int now, long long flow)
{
	if (flow == 0) return 0;
	if (now == n) return flow;
	long long nflow = 0, nn;
	for (int t = en[now]; t != -1; t = e[t].n){
		int to = e[t].v;
		if (e[t].w && lv[to] + 1 == lv[now]){
			nn = dfs(to, min(flow-nflow, (long long)e[t].w));
			if (nn > 0){
				e[t].w -= nn;
				nflow += nn;
				e[t^1].w += nn;
				if (nflow == flow) return nflow;
			}
			else lv[to] = -1; //is it okay?
		}
	}
	if (nflow == 0) lv[now] = -1; //is it okay?
	return nflow;
}
int main()
{
	scanf("%d %d", &n, &m);
	memset(en, -1, sizeof(en));
	for (int i = 0; i < m; i++){
		scanf("%d %d %d", &x, &y, &w);
		addedge(x, y, w);
	}
	long long maxflow = 0;
	while(bfs()){
		maxflow = maxflow + dfs(1, inf);
	}
	printf("%lld\n", maxflow);
	return 0;
}
