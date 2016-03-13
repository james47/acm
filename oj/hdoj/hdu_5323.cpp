/*************************************************************************
    > File Name: hdu_5323.cpp
    > Author: james47
    > Mail: 
    > Created Time: Wed Jul 29 09:16:37 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long ll;
const ll inf = (ll)1e15;
int L, R;
ll ans;
void dfs(ll l, ll r){
	if (l == 0){
		ans = min(ans, r);
		return;
	}
	if (r > L * 2) return;
	if (r >= ans || l < 0) return;
	dfs(l*2-2-r, r);
	dfs(l*2-1-r, r);
	dfs(l, r*2-l);
	dfs(l, r*2-l+1);
}
int main()
{
	while(scanf("%d %d", &L, &R) != EOF){
		ans = inf;
		dfs(L, R);
		if (ans == inf) puts("-1");
		else printf("%lld\n", ans);
	}
	return 0;
}
