#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

const double eps = 1e-6;
int n, m;
bool vis[20];
int a[20], d[20];
bool use[20];
double bestratio;
int edgesum, pointsum;
int e[20][20];
int tmpans[20], ans[20];
void dfs(int dep, int pos)
{
	if (dep == m){
		int cnt = 0;
		pointsum = 0;
		for (int i = 1; i <= n; i++)
			if (use[i]){
				cnt++;
				pointsum += a[i];
			}
		if (cnt < m) return;
		memset(d, 127, sizeof(d));
		memset(vis, false, sizeof(vis));
		int nx, mi = d[0] + 1;
		edgesum = 0;
		for (int j = 0; j <= m-1; j++){
			mi = d[0] + 1;
			for (int i = 1; i <= n; i++){
				if (use[i] && !vis[i] && d[i] < mi){
					nx = i;
					mi = d[i];
				}
			}
			vis[nx] = true;
			if (d[nx] != d[0]) edgesum += d[nx];
			for (int i = 1; i <= n; i++){
				if (use[i] && d[i] > e[nx][i]){
					d[i] = e[nx][i];
				}
			}
		}
		double tmp = double(edgesum)/double(pointsum);
		if (tmp < bestratio){
			bestratio = tmp;
			int p = 1;
			for (int i = 0; i < m; i++){
				while(!use[p]) p++;
				ans[i] = p;
				p++;
			}
		}
		else if (fabs(tmp - bestratio) < eps){
			int p = 1;
			for (int i = 0; i < m; i++){
				while(!use[p]) p++;
				tmpans[i] = p;
				p++;
			}
			int i;
			for (i = 0; i < m; i++){
				if (tmpans[i] > ans[i]) return;
				if (tmpans[i] < ans[i]) break;
			}
			if (i != m){
				for (int j = 0; j < m; j++)
					ans[j] = tmpans[j];
				bestratio = tmp;
			}
		}
		return;
	}
	for (int i = pos+1; i <= n; i++)
		if (!use[i]){
			use[i] = true;
			dfs(dep+1, i);
			use[i] = false;
		}
}
int main()
{
	while(scanf("%d %d", &n, &m) && n + m)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", a+i);
		int x, y, z;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++){
				scanf("%d", &z);
				e[i][j] = z;
			}
		bestratio = 1e10;
		memset(use, false, sizeof(use));
		dfs(0, 0);
		for (int i = 0; i < m-1; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[m-1]);
	}
	return 0;
}
