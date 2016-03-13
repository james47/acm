#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

struct E
{
	int next, y;
} edge[40010];
int col[210], dfn[210], low[210], stack[210], en[210], x[210], y[210];
int esize, n, top, ti1, cnt;
double d[210][210];
const double eps = 1e-8;
void insert(int u, int v)
{
	edge[++esize].y = v;
	edge[esize].next = en[u];
	en[u] = esize;
}
void dfs(int x)
{
	//printf("%d %d\n", x, time);
	dfn[x] = low[x] = ti1 ++;
	stack[top++] = x;
	for (int t = en[x]; t != -1; t = edge[t].next)
	{
		int y = edge[t].y;
		if (dfn[y] == -1){
			dfs(y);
			if (low[y] < low[x]) low[x] = low[y];
		}
		else if (col[y] == -1 && low[y] < low[x]){  //low[y] can be replaced by dfn[y], equal? not equal but make no difference to scc
			low[x] = low[y];
		}
	}
	if (dfn[x] == low[x])
	{
		cnt ++;
		while(stack[--top] != x) col[stack[top]] = cnt;
		col[x] = cnt;
	}
}
bool ok(double r)
{
	//new map
	memset(en, -1, sizeof(en));
	esize = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (d[i][j] < r * 2.0){
				insert(i, j + n);
				insert(j, i + n);
			}
			if (d[i][j+n] < r * 2.0){
				insert(i, j);
				insert(j + n, i + n);
			}
			if (d[i+n][j] < r * 2.0){
				insert(i + n, j + n);
				insert(j, i);
			}
			if (d[i+n][j+n] < r * 2.0){
				insert(j + n, i);
				insert(i + n, j);
			}
		}
	//printf("r is %lf, esize is %d\n", r, esize);
	//tarjan dfs
	memset(col, -1, sizeof(col));
	memset(low, -1, sizeof(low));
	memset(dfn, -1, sizeof(dfn));
	top = 0; ti1 = 0; cnt = 0;
	for (int i = 0; i < 2 * n; i++)
		if (dfn[i] == -1) dfs(i);
	//judge
	//for (int i = 0; i < n; i++)
	//	printf("color: %d %d %d\n", i, col[i], col[i+n]);
	for (int i = 0; i < n; i++)
		if (col[i] == col[i + n]) {
		//	printf("%d", col[i]);
			return false;}
	return true;
}
double dis(int i, int j)
{
	return sqrt(double(x[i] - x[j]) * double(x[i] - x[j]) +
		    double(y[i] - y[j]) * double(y[i] - y[j]));
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		double max = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d", &x[i], &y[i], &x[i+n], &y[i+n]);
		}
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				d[i][j] = d[j][i] = dis(i, j);
				if (d[i][j] > max) max = d[i][j];
				d[j][i+n] = d[i+n][j] = dis(i+n, j);
				if (d[i+n][j] > max) max = d[i+n][j];
				d[i][j+n] = d[j+n][i] = dis(i, j+n);
				if (d[i][j+n] > max) max = d[i][j+n];
				d[i+n][j+n] = d[j+n][i+n] = dis(i+n, j+n);
				if (d[i+n][j+n] > max) max = d[i+n][j+n];
			}
	//	for (int i = 0; i < n; i++)
	//		for (int j = i + 1; j < n; j++)
	//		{
	//			printf("%lf %lf %lf %lf\n", d[i][j], d[i][j+n], d[i+n][j], d[i+n][j+n]);
	//		}
		double l = 0.0, r = max, ans = 0.0;
		while (l + eps <= r)
		{
	//		puts("yes");
			double mid = (l + r) / 2.0;
	//		printf("%lf\n", mid);
			if (ok(mid))
			{
	//			printf("%lf is ok\n", mid);
				if (mid > ans)
					ans = mid;
				l = mid + eps;
			}
			else
				r = mid - eps;
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
