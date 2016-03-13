/*************************************************************************
    > File Name: d.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sat Sep 12 20:15:56 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 101000;
const int mod = 1e9+7;

int d[maxn];
char sa[maxn], sb[maxn];
int dp[maxn][16];

int dfs(int pos, int pre, bool bound){
	if (pos == 0){ return pre; }
	if (!bound && dp[pos][pre] != -1) return dp[pos][pre];
	int ret = 0;
	int lim = bound? d[pos]: 9;
	for (int i = 0; i <= lim; i++){
		int tmp = dfs(pos-1, pre^i, bound&&i==lim);
		ret += tmp;
		if (ret >= mod) ret -= mod;
	}
	if (!bound){ dp[pos][pre] = ret; }
	return ret;
}

int solve(char* s){
	int p = 0;
	while(s[p] == '0') p++;
	int len = strlen(s);
	if (p == len) return 0;
	int i, j;
	for (i = len-1, j = 1; i >= p; i--, j++)
		d[j] = s[i] - '0';
	j--;
	return dfs(j, 0, true);
}
int cal(char *s){
	int len = strlen(s);
	int ret = 0;
	for (int i = 0; i < len; i++)
		ret ^= s[i] - '0';
	return ret;
}

int T;
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &T); int cas = 0;
	while(T--){
		scanf("%s %s", sa, sb);
		printf("Case #%d: ", ++cas);
		int res = (solve(sb) - solve(sa) + cal(sa) + mod) % mod;
		printf("%d\n", res);
	}
	return 0;
}
