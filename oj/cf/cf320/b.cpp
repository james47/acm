/*************************************************************************
    > File Name: b.cpp
    > Author: james47
    > Mail: 
    > Created Time: Wed Sep 16 23:37:37 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 200100;
typedef long long ll;
int n, k, x;
int cnt[maxn], a[maxn];
void work(int d){
	int len = 0;
	while(d){
		if (d&1) cnt[len]++;
		d >>= 1;
		len ++;
	}
}
ll cal(ll sum, int d){
	int len = 0; ll p = 1;
	while(d){
		if ((d&1) && cnt[len]==1) sum ^= p;
		p <<= 1;
		d >>= 1;
		len ++;
	}
	return sum;
}
int main()
{
	scanf("%d %d %d", &n, &k, &x);
	ll f = 1;
	for (int i = 0; i < k; i++) f = f * x;
	memset(cnt, 0, sizeof(cnt));
	ll sum = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", a+i);
		work(a[i]);
		sum |= a[i];
	}
	ll ans = -1, tmp;
	for (int i = 0; i < n; i++){
		tmp = cal(sum, a[i]);
		tmp = tmp | (f * a[i]);
		if (tmp > ans) ans = tmp;
	}
	printf("%lld\n", ans);
//	printf("%I64d\n", ans);
	return 0;
}
