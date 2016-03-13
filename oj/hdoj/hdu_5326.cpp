/*************************************************************************
    > File Name: hdu_5326.cpp
    > Author: james47
    > Mail: 
    > Created Time: Wed Jul 29 09:38:42 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> v[110];
int rt[110];
int dp[110];

void dfs(int x){
	dp[x] = 0;
	for (int i = 0, len = (int)v[x].size(); i < len; i++){
		dfs(v[x][i]);
		dp[x] += dp[v[x][i]] + 1;
	}
}
int main()
{
	while(scanf("%d %d", &n, &k) != EOF){
		for (int i = 1; i <= n; i++){
			v[i].clear();
			rt[i] = 1;
		}
		int a, b;
		for (int i = 1; i < n; i++){
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			rt[b] = 0;
		}
		for (int i = 1; i <= n; i++)
			if (rt[i]){
				dfs(i);
				break;
			}
		int ans = 0;
		for (int i = 1; i <= n; i++) if (dp[i] == k) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
