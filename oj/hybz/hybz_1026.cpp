/*************************************************************************
    > File Name: hybz_1026.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sun Aug  2 15:34:35 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int ZERO = 12;
int d[15];
int dp[15][13];
int dfs(int pos, int pre, bool bound){
	if (pos == 0) return 1;
	if (!bound && dp[pos][pre] != -1) return dp[pos][pre];
	int ret = 0, lim = bound? d[pos]: 9, npre;
	for (int i = 0; i <= lim; i++){
		if (abs(i-pre) < 2) continue;
		if (i == 0 && pre == ZERO) npre = ZERO;
		else npre = i;
		ret += dfs(pos-1, npre, bound&&(i==lim));
	}
	if (!bound) dp[pos][pre] = ret;
	return ret;
}
int solve(int x){
	int len = 0;
	while(x){
		d[++len] = x%10;
		x /= 10;
	}
	return dfs(len, ZERO, true);
}
int a, b;
int main()
{
	memset(dp, -1, sizeof(dp));
	while(scanf("%d %d", &a, &b) == 2){
		printf("%d\n", solve(b) - solve(a-1));
	}
	return 0;
}
