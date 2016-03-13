#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int, int> P;
struct e{
	int v, n, w;
} e[10010];
int d[110], en[110];
int n, m, esize;
bool vis[110];
void insert(int u, int v, int w)
{
	e[esize].v = v;
	e[esize].w = w;
	e[esize].n = en[u];
	en[u] = esize ++;
}
/*
int dijkstra(int st, int ed)
{
	memset(d, -1, sizeof(d));
	memset(vis, false, sizeof(vis));
	d[st] = 0;
	priority_queue<P, vector<P>, greater<P> > q;
	q.push(make_pair(0, st));
	while(!q.empty())
	{
		P pp = q.top(); q.pop();
		int u = pp.second;
		if (u == ed) return d[u];
		if (vis[u]) continue;
		vis[u] = true;
		for (int t = en[u]; t != -1; t = e[t].n){
			int v = e[t].v;
			if (d[v] == -1 || d[v] > d[u] + e[t].w){
				d[v] = d[u] + e[t].w;
				q.push(make_pair(d[v], v));
			}
		}
	}
	return d[ed];
}
*/
struct cmp{
	bool operator()(const int& a, const int& b){
		return d[a] > d[b];
	}
};
int dijkstra(int st, int ed)
{
	memset(d, -1, sizeof(d));
	memset(vis, false, sizeof(vis));
	d[st] = 0;
	priority_queue<int, vector<int>, cmp> q;
	q.push(st);
	while(!q.empty())
	{
		int u = q.top(); q.pop();
		if (u == ed) return d[u];
		if (vis[u]) continue;
		vis[u] = true;
		for (int t = en[u]; t != -1; t = e[t].n){
			int v = e[t].v;
			if (d[v] == -1 || d[v] > d[u] + e[t].w){
				d[v] = d[u] + e[t].w;
				q.push(v);
			}
		}
	}
	return d[ed];
}

int main()
{
	while(scanf("%d %d", &n, &m) != EOF && (n+m))
	{
		int x, y, z;
		memset(en, -1, sizeof(en));
		esize = 0;
		for (int i = 0; i < m; i++){
			scanf("%d %d %d", &x, &y, &z);
			insert(x, y, z);
			insert(y, x, z);
		}
		printf("%d\n", dijkstra(1, n));
	}
	return 0;
}
