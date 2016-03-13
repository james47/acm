//#pragma comment(linker, "/STACK:1024000000,1024000000") 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 100010;
int T, n, m, dfn;
int l[N], r[N], dep[N], p[N][20];
int sum[N], dp[N];
int sd[N * 2], ss[N * 2];
vector<int> e[N];
vector<pair<pair<int, int>, int> > q[N];

void dfs(int cur, int fa, int Dep){
	l[cur] = dfn ++;
	p[cur][0] = fa;
	int tmp;
	for (int i = 1; i < 20; i++){
		tmp = p[cur][i-1];
		if (tmp) p[cur][i] = p[tmp][i-1];
		else p[cur][i] = 0;
	}
	dep[cur] = Dep;
	for (int i = 0, len = (int)e[cur].size(); i < len; i++){
		int nex = e[cur][i];
		if (nex != fa) dfs(nex, cur, Dep+1);
	}
	r[cur] = dfn ++;
}

int lca(int x, int y){
	if (dep[x] < dep[y]) swap(x, y);
	int tmp;
	for (int i = 19; i >= 0; i--){
		tmp = p[x][i];
		if (tmp && dep[tmp] >= dep[y]) x = tmp;
	}
	if (x == y) return x;
	for (int i = 19; i >= 0; i--){
		if (p[x][i] != p[y][i] && p[x][i] != 0) x = p[x][i], y = p[y][i];
	}
	return p[x][0];
}

int query(int x, int* sum){
	int ret = 0;
	for (int i = x; i > 0; i -= (i & -i))
		ret += sum[i];
	return ret;
}
void add(int x, int v, int* sum){
	for (int i = x; i <= n*2; i += (i & -i))
		sum[i] += v;
}
void work(int cur, int fa){
	sum[cur] = 0;
	for (int i = 0, len = (int)e[cur].size(); i < len; i++){
		int nex = e[cur][i];
		if (nex != fa){
			work(nex, cur);
			sum[cur] += dp[nex];
		}
	}
	dp[cur] = sum[cur];
	for (int i = 0, len = (int)q[cur].size(); i < len; i++){
		int u = q[cur][i].first.first, v = q[cur][i].first.second, w = q[cur][i].second;
		int tmp = query(l[u], ss) + query(l[v], ss) - query(l[u], sd) - query(l[v], sd) + sum[cur];
		dp[cur] = max(dp[cur], tmp + w);
	}
	add(l[cur], sum[cur], ss);
	add(r[cur], -sum[cur], ss);
	add(l[cur], dp[cur], sd);
	add(r[cur], -dp[cur], sd);
}

int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++){
			e[i].clear();
			q[i].clear();
		}
		int u, v, w;
		for (int i = 1; i < n; i++){
			scanf("%d %d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfn = 1;
		dfs(1, 0, 1);
		for (int i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &w);
			q[lca(u, v)].push_back(make_pair(make_pair(u, v), w));
		}
		memset(ss, 0, sizeof(int) * (n * 2 + 1));
		memset(sd, 0, sizeof(int) * (n * 2 + 1));
		work(1, 0);
		printf("%d\n", dp[1]);
	}
	return 0;
}
