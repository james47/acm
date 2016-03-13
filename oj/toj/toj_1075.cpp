#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int inf, n;
int d[110][110];
void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			if (d[i][k] == inf) continue;
			else for (int j = 1; j <= n; j++){
				if (d[k][j] == inf) continue;
				if (d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
}
int main()
{
	while(scanf("%d", &n), n)
	{
		memset(d, 127, sizeof(d));
		inf = d[0][0];
		for (int i = 1; i <= n; i++){
			int t, y, w;
			scanf("%d", &t);
			for (int j = 0; j < t; j++){
				scanf("%d %d", &y, &w);
				d[i][y] = w;
			}
		}
		floyd();
		int ansp, ans = inf;
		for (int i = 1; i <= n; i++){
			int tmp = 0;
			for (int j = 1; j <= n; j++) if (j != i) tmp = max(tmp, d[i][j]);
			if (tmp < ans){
				ansp = i;
				ans = tmp;
			}
		}
		if (ans == inf) puts("disjoint");
		else printf("%d %d\n", ansp, ans);
	}
	return 0;
}
