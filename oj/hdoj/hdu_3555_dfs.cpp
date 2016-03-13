/*************************************************************************
    > File Name: hdu_3555.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sun Aug  2 14:02:01 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
ll dp[30][3];
int d[30];

ll dfs(int pos, bool has49, bool is4, bool bound){ //pos为当前枚举的位，has49表示是否已有49，is4表示前一位是否是4，bound表示之前是否有上界，即之前是否都是n对应位
	if (pos == 0) return has49;
	int st = 0;
	if (has49) st = 2;
	else if (is4) st = 1;
	if (!bound && dp[pos][st] != -1) return dp[pos][st];	//记忆化搜索
	int lim = bound? d[pos]: 9;
	ll ret = 0;
	for (int i = 0; i <= lim; i++){							//枚举当前位填的数
		ret += dfs(pos-1, has49||(is4&&i==9), i==4, bound&&i==lim);
	}
	if (!bound) dp[pos][st] = ret;
	return ret;
}

ll solve(ll n){
	int len = 0;
	while(n){
		d[++len] = n%10;
		n /= 10;
	}
	return dfs(len, false, false, true);
}

int T;
ll n;
int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &T);
	while(T--){
		//scanf("%I64d", &n);
		//printf("%I64d\n", solve(n));
		scanf("%lld", &n);
		printf("%lld\n", solve(n));
	}
	return 0;
}
