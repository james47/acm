/*************************************************************************
    > File Name: poj_3311.cpp
    > Author: james47
    > Mail: 
    > Created Time: Mon Aug  3 18:49:33 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int n, oo;
int d[11][11];
int dp[11][1<<11];
int main()
{
	while(scanf("%d", &n) && n){
	//	memset(d, 127, sizeof(d));
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++) scanf("%d", &d[i][j]);
		for (int k = 0; k <= n; k++)
			for (int i = 0; i <= n; i++){
				if (d[i][k] == oo) continue;
				for (int j = 0; j <= n; j++)
					if (d[k][j] != oo) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		memset(dp, 127, sizeof(dp));
		oo = dp[0][0];
		dp[0][0] = 0;
		for (int i = 0; i < (1<<(n+1))-1; i++)
			for (int j = 0; j <= n; j++)
				if (dp[j][i] != oo){
					for (int k = 0; k <= n; k++)
						if (!(i&(1<<k)))
							dp[k][i|(1<<k)] = min(dp[k][i|(1<<k)], dp[j][i] + d[j][k]);
				}
		printf("%d\n", dp[0][(1<<(n+1))-1]);
	}
	return 0;
}
