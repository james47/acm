#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> edge;
int n, m, w, x, st;
vector<edge> e[610];
long long f[610][2100], g[610][2100];
int c[610], v[610], bfn[610], in[610];
bool reach[610];
int main()
{
	while(scanf("%d %d %d %d", &n, &m, &w, &x) != EOF)
	{
		for (int i = 1; i <= n; i++){
			scanf("%d %d", c+i, v+i); 
			e[i].clear();
		}
		memset(in, 0, sizeof(in));
		int xx, yy, ww;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &xx, &yy, &ww);
			e[xx].push_back(make_pair(yy, ww));
			in[yy] ++;
		}
		queue<int> q;
		for (int i = 1; i <= n; i++)
			if (in[i] == 0) q.push(i);
		int cnt = 0;
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			bfn[++cnt] = u;
			if (u == x) st = cnt;
			for (int i = 0; i < e[u].size(); i++){
				int v = e[u][i].first;
				in[v] --;
				if (!in[v]) q.push(v);
			}
		}
		memset(reach, false, sizeof(reach));
		reach[x] = true;
		long long ans = 1 << 30, maxv = 0;
		ans <<= 30;
		memset(f, 0, sizeof(f));
		for (int mark = st; mark <= n; mark++){
			int i = bfn[mark];
			if (!reach[i]) continue;
			for (int j = 0; j <= w; j++){
				if (j >= c[i]){
					long long tmp = f[i][j-c[i]] + v[i]; 
					if (f[i][j] < tmp){
						f[i][j] = tmp;
						g[i][j] = g[i][j-c[i]];
					}
					else if (f[i][j] == tmp){
						g[i][j] = min(g[i][j], g[i][j-c[i]]);
					}
				}
				for (int t = 0; t < e[i].size(); t++){
					int v = e[i][t].first, l = e[i][t].second;
					reach[v] = true;
					if (f[i][j] > f[v][j]){
						f[v][j] = f[i][j];
						g[v][j] = g[i][j] + l * j;
					}
					else if (f[i][j] == f[v][j]){
						g[v][j] = min(g[v][j], g[i][j] + l * j);
					}
				}
				if (f[i][j] > maxv){
					maxv = f[i][j];
					ans = g[i][j];
				}
				else if (f[i][j] == maxv) ans = min(ans, g[i][j]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
