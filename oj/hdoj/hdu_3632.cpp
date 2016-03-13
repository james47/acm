/*************************************************************************
    > File Name: a.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sat Aug  8 13:13:34 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int T, cas = 0;
int n;
int v[110];
int a[110][110];
bool dp[110][110];
int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
			a[i][0] = a[i][n+1] = 1;
		}
		for (int i = 0; i <= n+1; i++) a[0][i] = a[n+1][i] = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i <= n; i++) dp[i+1][i] = dp[i][i+1] = true;
		for (int len = 1; len <= n; len++){
			for (int i = 0; i <= n; i++){
				if (i+len > n+1) break;
				for (int j = i+1; j < i+len && j <= n; j++){
					//printf("%d %d %d\n", i, j, i+len);
					if (dp[i][j] && dp[j][i+len] && (a[i][j] || a[i+len][j])) dp[i+len][i] = dp[i][i+len]= true;
					//printf("%d %d %d %d\n", dp[i][j], dp[j][i+len], a[i][j], a[i+len][j]);
				}
			}
		}
		/*
		for (int i = 0; i <= n+1; i++){
			for (int j = 0; j <= n+1; j++) printf("%d ", dp[i][j]);
			puts("");
		}
		*/
		int ans = -100;
		for (int i = 1; i <= n; i++)
			if (dp[0][i] && dp[i][n+1]) ans = max(ans, v[i]);
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
