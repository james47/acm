/*************************************************************************
    > File Name: hdu_1693.cpp
    > Author: james47
    > Mail: 
    > Created Time: Wed Aug  5 14:17:04 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
int T, n, m, cas = 0;
ll dp[12][12][1<<12];
int a[12][12];
int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		int left, up;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				for (int k = 0; k < (1<<(m+1)); k++) if (dp[i][j][k]){
					left = k & 1 << j; up = k & 1 << j+1;
					if (a[i][j]){
						if (!left && !up)
							dp[i][j+1][k^(1<<j)^(1<<j+1)] += dp[i][j][k];
						else if (left && up)
							dp[i][j+1][k^(1<<j)^(1<<j+1)] += dp[i][j][k];
						else{
							dp[i][j+1][k] += dp[i][j][k];
							dp[i][j+1][k^(1<<j)^(1<<j+1)] += dp[i][j][k];
						}
					}
					else if (!left && !up) dp[i][j+1][k] += dp[i][j][k];
				}
			}
			for (int k = 0; k < (1<<(m+1)); k++)
				if (!(k & 1<<m)) dp[i+1][0][k<<1] = dp[i][m][k];
		}
		printf("Case %d: There are %lld ways to eat the trees.\n", ++cas, dp[n-1][m][0]);
	}
	return 0;
}
