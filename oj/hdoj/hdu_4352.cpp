/*************************************************************************
    > File Name: hdu_4352.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sun Aug  2 16:31:20 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

int d[25];
ll dp[25][1<<10][11];
int cal(int x){
	int ret = 0;
	while(x){
		ret ++;
		x &= (x-1);
	}
	return ret;
}
int get(int st, int x){
	for (int i = x; i < 10; i++)
		if (st & (1 << i)) return (st^(1<<i))|(1<<x);
	return st | (1 << x);
}
ll dfs(int pos, int st, int k, bool zero, bool bound){
	if (pos == 0) return cal(st) == k;
	if (!bound && dp[pos][st][k] != -1) return dp[pos][st][k];
	ll ret = 0; int lim = bound? d[pos]: 9;
	for (int i = 0; i <= lim; i++){
		ret += dfs(pos-1, zero&&i==0? 0: get(st, i), k, zero&&i==0, bound&&i==lim);
	}
	if (!bound) dp[pos][st][k] = ret;
	return ret;
}
ll solve(ll x, int k){
	int len = 0;
	while(x){
		d[++len] = x % 10;
		x /= 10;
	}
	return dfs(len, 0, k, true, true);
}

int T, cas, k;
ll a, b;
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &T); cas = 0;
	while(T--){
		scanf("%lld %lld %d", &a, &b, &k);
		printf("Case #%d: %lld\n", ++cas, solve(b, k) - solve(a-1, k));
	}
	return 0;
}
