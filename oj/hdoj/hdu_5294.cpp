#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int inf = (int)1e6;
struct edge{
	int v, w, next;
} e[150000], ee[150000];
int n, m, u, v, w;
int ans1, esize, esize1, sou, tar;
int en[2010], en1[2010], lv[2010], q[2010], cur[2010];

void addedge(int u, int v, int w){
	e[esize].v = v;
	e[esize].w = w;
	e[esize].next = en[u];
	en[u] = esize ++;
}
int dis[2010], dis0[2010];
bool used[2010];
void dijkstra(int s){
	memset(dis, 127, sizeof(dis)); int oo = dis[0];
	memset(used, false, sizeof(used));
	dis[s] = 0; dis0[s] = 0;
	priority_queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(-dis[s], -dis0[s]), s));
	while(!q.empty()){
		int u = q.top().second; q.pop();
		if (used[u]) continue;
		used[u] = true;
		for (int t = en[u]; t != -1; t = e[t].next){
			int v = e[t].v;
			if (dis[v] == oo || dis[u] + e[t].w < dis[v]){
				dis[v] = dis[u] + e[t].w;
				dis0[v] = dis0[u] + 1;
			}
			else if (dis[u] + e[t].w == dis[v]){
				dis0[v] = min(dis0[v], dis0[u]+1);
			}
			else continue;
			q.push(make_pair(make_pair(-dis[v], -dis0[v]), v));
		}
	}
}

void add(int u, int v, int w){
	ee[esize1].v = v;
	ee[esize1].w = w;
	ee[esize1].next = en1[u];
	en1[u] = esize1 ++;
}
bool bfs(){
	memset(lv, -1, sizeof(lv));
	int head, tail;
	lv[tar] = head = tail = 0;
	q[tail++] = tar;
	while(head < tail){
		int u = q[head++];
		for (int t = en1[u]; t != -1; t = ee[t].next){
			int v = ee[t].v;
			if (lv[v] == -1 && ee[t^1].w > 0){
				lv[v] = lv[u] + 1;
				if (v != sou) q[tail++] = v;
			}
		}
	}
	return lv[sou] != -1;
}
int dfs(int u, int maxf){
	if (maxf == 0) return 0;
	if (u == tar) return maxf;
	int ret = 0, res, flow;
	for (int &t = cur[u]; t != -1; t = ee[t].next){
		int v = ee[t].v;
		if (ee[t].w > 0 && lv[v] + 1 == lv[u]){
			res = min(maxf - ret, ee[t].w);
			flow = dfs(v, res);
			if (flow > 0){
				ee[t].w -= flow;
				ee[t^1].w += flow;
				ret += flow;
				if (maxf == ret) return ret;
			}
		}
	}
	return ret;
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF){
		memset(en, -1, sizeof(en));
		esize = 0;
		for (int i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &w);
			addedge(u, v, w);
			addedge(v, u, w);
		}
		dijkstra(1);
		ans1 = m - dis0[n];
		 
		memset(en1, -1, sizeof(en1));
		esize1 = 0;
		for (int i = 1; i <= n; i++){
			for (int t = en[i]; t != -1; t = e[t].next){
				int v = e[t].v;
				if (dis[i] + e[t].w == dis[v]){
					add(i, v, 1);
					add(v, i, 0);
				}
			}
		}
		int maxflow = 0;
		sou = 1, tar = n;
		while(bfs()){
			for (int i = 1; i <= n; i++) cur[i] = en1[i];
			maxflow = maxflow + dfs(sou, inf);
		}
		printf("%d %d\n", maxflow, ans1);
	}
	return 0;
}
