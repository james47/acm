/*************************************************************************
    > File Name: poj_2411.cpp
    > Author: james47
    > Mail: 
    > Created Time: Mon Aug  3 17:48:34 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

long long dp[12][1<<11];
long long ans[12][12];
int n, m;
void add(int r, int pos, int st, long long val){
	dp[r][st] += val;
	for (int i = pos; i+1 < m; i++){
		if (!(st&(1<<i))&&!(st&(1<<(i+1)))) add(r, i+2, st|(1<<i)|(1<<(i+1)), val);
	}
}
int main()
{
	memset(ans, -1, sizeof(ans));
	while(scanf("%d %d", &n, &m) == 2){
		if (n == 0 && m == 0) break;
		if (m > n) swap(n, m);
		if (ans[n][m] != -1){
			printf("%lld\n", ans[n][m]);
			continue;
		}
		memset(dp, 0, sizeof(dp));
		add(0, 0, 0, 1);
		for (int i = 0; i+1 < n; i++){
			for (int j = 0; j < (1<<m); j++){
				if (dp[i][j]) add(i+1, 0, (~j)&((1<<m)-1), dp[i][j]);
			}
		}
		ans[n][m] = dp[n-1][(1<<m)-1];
		printf("%lld\n", ans[n][m]);
	}
	return 0;
}
