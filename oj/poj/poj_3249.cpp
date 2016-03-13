#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

int n, m, esize, x, y;
int a[100100], en[100100], in[100100], bfn[100100], dp[100100];
bool ed[100100];
struct edge{
	int v, n;
} e[1000100];
void addedge(int u, int v)
{
	e[esize].v = v;;
	e[esize].n = en[u];
	en[u] = esize ++;
}
queue<int> q;
int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", a+i);
		memset(en, -1, sizeof(en));
		memset(in, 0, sizeof(0));
		memset(ed, true, sizeof(ed));
		esize = 0;
		for (int i = 0; i < m; i++){
			scanf("%d %d", &x, &y);
			addedge(x, y);
			in[y]++;
			ed[x] = 0;
		}
		for (int i = 1; i <= n; i++)
			if (!in[i]) q.push(i);
		int ans = -2147483640;
		int cnt = 0;
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			bfn[cnt++] = u;
			for (int t = en[u]; t != -1; t = e[t].n){
				int v = e[t].v;
				in[v] --;
				if (in[v] == 0)	q.push(v);
			}
		}
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++){
			int u = bfn[i];
			if (dp[u] == -1) dp[u] = a[u];
			if (ed[u]) ans = max(ans, dp[u]);
			for (int t = en[u]; t != -1; t = e[t].n){
				int v = e[t].v;
				if (dp[v] == -1 || dp[v] < dp[u] + a[v])
					dp[v] = dp[u] + a[v];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
