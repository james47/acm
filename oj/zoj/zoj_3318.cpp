#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T, n, m, s, t, oo;
int d[40], q[40], dp[40];
int len[40][40];
bool map[40][40][40], e[40][40];
int bfs()
{
	memset(d, 127, sizeof(d));
	oo = d[0];
	d[s] = 0;
	int head, tail;
	head = tail = 0;
	q[tail++] = s;
	while(head < tail)
	{
		int u = q[head++];
		for (int v = 1; v <= n; v++) if (e[u][v] && d[v] > d[u] + 1){
			d[v] = d[u] + 1;
			q[tail++] = v;
		}
	}
	return d[t];
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d %d", &n, &m, &s, &t);
		memset(map, 0, sizeof(map));
		int r, x, y;
		for (int i = 0; i < m; i++){
			scanf("%d", &r);
			for (int j = 0; j < r; j++){
				scanf("%d %d", &x, &y);
				map[i][x][y] = true;
				map[i][y][x] = true;
			}
		}
		for (int i = 0; i < m; i++){
			memset(e, 1, sizeof(e));
			for (int j = i; j < m; j++){
				for (int k = 1; k <= n; k++)
					for (int l = 1; l <= n; l++)
						e[k][l] &= map[j][k][l];
				len[i][j] = bfs();
			}
		}
		dp[0] = len[0][0];
		for (int i = 1; i < m; i++){
			if (len[0][i] != oo) dp[i] = len[0][i] * (i+1);
			else dp[i] = oo;
			for (int j = 0; j < i; j++){
				if (len[j+1][i] != oo)
					dp[i] = min(dp[i], dp[j] + (i-j) * len[j+1][i] + 1);
			}
		}
		printf("%d\n", dp[m-1]);
	}
	return 0;
}
