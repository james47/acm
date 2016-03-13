#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<ctime>
#include<string>
using namespace std;

int n, d;
int cost[110][110];
int dp[110][110][5];
int night[110][5];
int main()
{
	while(scanf("%d%d", &n, &d) != EOF)
	{
		memset(cost, -1, sizeof(cost));
		int m, y, c;
		for (int i = 0; i < n; i++){
			for (int j = 1; j <= 3; j++)
				scanf("%d", &night[i][j]);
			scanf("%d", &m);
			for (int j = 0; j < m; j++){
				scanf("%d %d", &y, &c);
				cost[i][y] = c;
			}
		}
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++){
				if (cost[i][k] == -1) continue;
				for (int j = 0; j < n; j++){
					if (cost[k][j] == -1) continue;
					if (cost[i][j] == -1 || cost[i][j] > cost[i][k] + cost[k][j])
						cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		//for (int i = 0; i < n; i++)
		//	for (int j = 0; j < n; j++)
		//		printf("%d %d %d\n", i, j, cost[i][j]);
		memset(dp, -1, sizeof(dp));
		dp[1][0][1] = night[0][1];
		dp[2][0][2] = night[0][1] + night[0][2];
		for (int i = 1; i < n; i++)
			if (cost[0][i] != -1 && dp[1][0][1] >= cost[0][i]){
				dp[2][i][1] = dp[1][0][1] - cost[0][i] + night[i][1];
			}
		d--;
		for (int i = 2; i < d; i++)
			for (int j = 0; j < n; j++){
				for (int k = 1; k <= 3; k++){	
					//printf("%d %d %d %d\n", i, j, k, dp[i][j][k]);
					if (dp[i][j][k] == -1) continue;
					int tmp = k+1;
					if (tmp > 3) tmp = 3;
					dp[i+1][j][tmp] = max(dp[i+1][j][tmp], dp[i][j][k] + night[j][tmp]);
					for (int to = 0; to < n; to++){
						if (cost[j][to] != -1 && dp[i][j][k] >= cost[j][to]){
							dp[i+1][to][1] = max(dp[i+1][to][1], dp[i][j][k] - cost[j][to] + night[to][1]);
						}
					}
				}
			}
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int k = 1; k <= 3; k++)
				ans = max(ans, dp[d][i][k]);
		printf("%d\n", ans);
	}
	return 0;
}

