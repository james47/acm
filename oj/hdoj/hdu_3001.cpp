/*************************************************************************
    > File Name: hdu_3001.cpp
    > Author: james47
    > Mail: 
    > Created Time: Mon Aug  3 19:14:49 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int get(int x, int t){
	int ret = t;
	while(x){
		x--;
		ret *= 3;
	}
	return ret;
}
int cal(int st, int x){
	while(x){
		x--; 
		st /= 3;
	}
	return st % 3;
}
int n, m, oo;
int d[11][11];
int dp[10][100000];
int main()
{
	while(scanf("%d %d", &n, &m) == 2){
		memset(d, 127, sizeof(d));
		oo = d[0][0];
		int x, y, z;
		for (int i = 0; i < m; i++){
			scanf("%d %d %d", &x, &y, &z);
			x--, y--;
			d[x][y] = min(d[x][y], z);
			d[y][x] = min(d[y][x], z);
		}
		memset(dp, 127, sizeof(dp));
		for (int i = 0; i < n; i++) dp[i][get(i, 1)] = 0;
		int all = 1;
		for (int i = 0; i < n; i++) all *= 3;
		for (int i = 0; i < all; i++)
			for (int j = 0; j < n; j++)
				if (dp[j][i] != oo){
					for (int k = 0; k < n; k++){
						int ik = cal(i, k);
						if (d[j][k] != oo && ik != 2){
							int k1 = get(k, 1), k2 = k1 * 2;// get(k, 2);
							if (ik == 1) dp[k][i+k2-k1] = min(dp[k][i+k2-k1], dp[j][i] + d[j][k]);
							else dp[k][i+k1] = min(dp[k][i+k1], dp[j][i] + d[j][k]);
						}
					}
				}
		int ans = oo, need = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < all; j++)
				if (dp[i][j] != oo){
					bool flag = true;
					int tmp = j, cnt = n;
					while(cnt){
						if (tmp % 3 == 0){
							flag = false;
							break;
						}
						tmp /= 3;
						cnt--;
					}
					if (flag) ans = min(ans, dp[i][j]);
				}
		if (ans == oo) puts("-1");
		else printf("%d\n", ans);
	}
	return 0;
}
