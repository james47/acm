/*************************************************************************
    > File Name: hdu_2089.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sun Aug  2 15:15:16 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;


int d[15];
int dp[15][2];
int dfs(int pos, bool is6, bool bound){
	if (pos == 0) return 1;
	if (!bound && dp[pos][is6] != -1) return dp[pos][is6];
	int ret = 0, lim = bound? d[pos]: 9;
	for (int i = 0; i <= lim; i++){
		if (i == 4) continue;
		if (is6 && i == 2) continue;
		ret += dfs(pos-1, i==6, bound&&(i==lim));
	}
	if (!bound) dp[pos][is6] = ret;
	return ret;
}

int solve(int x){
	int len = 0;
	while(x){
		d[++len] = x%10;
		x /= 10;
	}
	return dfs(len, false, true);
}

int a, b;
int main()
{
	memset(dp, -1, sizeof(dp));
	while(scanf("%d %d", &a, &b) == 2){
		if (a == 0 && b == 0) break;
		printf("%d\n", solve(b) - solve(a-1));
	}
	return 0;
}
