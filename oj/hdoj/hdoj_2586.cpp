#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int, int> P;
const int maxn = 40100;

int T, n, m, x, y, z;
int f[maxn], d[maxn], ans[300];
bool vis[maxn];
vector<P> e[maxn], q[maxn];

int getf(int x)
{
	if (f[x] == x) return x;
	return f[x] = getf(f[x]);
}
void unionxy(int x, int y)
{
	int xroot = getf(x), yroot = getf(y);
	f[yroot] = xroot;
}
void tarjan(int x)
{
	f[x] = x;
	vis[x] = true;
	for (int i = 0; i < q[x].size(); i++){
		int v = q[x][i].first, id = q[x][i].second;
		if (vis[v]){
			int lca = f[getf(v)];
			ans[id] = d[x] + d[v] - 2 * d[lca];
		}
	}
	for (int i = 0; i < e[x].size(); i++){
		int v = e[x][i].first, w = e[x][i].second;
		if (!vis[v]){
			d[v] = d[x] + w;
			tarjan(v);
			unionxy(x, v);
			f[getf(x)] = x;
		}
	}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i <= n; i++){
			q[i].clear(); e[i].clear();
		}
		for (int i = 1; i < n; i++){
			scanf("%d%d%d", &x, &y, &z);
			e[x].push_back(make_pair(y, z));
			e[y].push_back(make_pair(x, z));
		}
		for (int i = 0; i < m; i++){
			scanf("%d %d", &x, &y);
			if (x == y) ans[i] = 0;
			else{
				q[x].push_back(make_pair(y, i));
				q[y].push_back(make_pair(x, i));
			}
		}
		memset(vis, 0, sizeof(vis));
		d[1] = 0;
		tarjan(1);
		for (int i = 0; i < m; i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}
