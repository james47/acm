/*************************************************************************
    > File Name: poj_3252.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sun Aug  2 15:56:52 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int base = 32;
int d[35];
int dp[35][65][2];
int dfs(int pos, int del, bool zero, bool bound){
	if (pos == 0) return del >= base;
	if (!bound && dp[pos][del][zero] != -1) return dp[pos][del][zero];
	int ret = 0, lim = bound? d[pos]: 1;
	for (int i = 0; i <= lim; i++){
		ret += dfs(pos-1, del + (i==0&&!zero) - (i==1), zero&&i==0, bound&&i==lim);
	}
	if (!bound) dp[pos][del][zero] = ret;
	return ret;
}

int solve(int x){
	int len = 0;
	while(x){
		d[++len] = x&1;
		x >>= 1;
	}
	return dfs(len, base, true, true);
}
int a, b;
int main()
{
	memset(dp, -1, sizeof(dp));
	while(scanf("%d %d", &a, &b) != EOF){
		printf("%d\n", solve(b) - solve(a-1));
	}
	return 0;
}
