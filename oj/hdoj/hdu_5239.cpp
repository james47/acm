/*************************************************************************
    > File Name: hdu_5239.cpp
    > Author: james47
    > Mail: 
    > Created Time: Wed Jul 29 15:01:55 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
const ull p = 9223372034707292160ll;
const int maxn = (int)1e5+10;

struct tree{
	ull sum, nxsum;
	int f;
} t[maxn<<2];
ull a[maxn];


void pushup(int rt){
	if (t[rt<<1].f && t[rt<<1|1].f){
		t[rt].f = 1;
		t[rt].sum = t[rt<<1].sum + t[rt<<1|1].sum;
		if (t[rt].sum >= p) t[rt].sum -= p;
	}
}

ull mul(ull a, ull b){
	ull ret = 0;
	a %= p, b %= p;
	while(b){
		if (b&1){
			ret += a;
			if (ret >= p) ret -= p;
		}
		a <<= 1; b >>= 1;
		if (a >= p) a -= p;
	}
	return ret;
}
void build(int rt, int l, int r){
	t[rt].f = 0;
	if (l == r){
		t[rt].sum = a[l];
		t[rt].nxsum = mul(a[l], a[l]);
		if (t[rt].sum == t[rt].nxsum) t[rt].f = 1;
		return;
	}
	t[rt].sum = t[rt].nxsum = 0;
	int m = l + r >> 1;
	build(rt<<1, l, m);
	build(rt<<1|1, m+1, r);
}
ull update(int L, int R, int rt, int l, int r){
	if (t[rt].f && L <= l && r <= R) return t[rt].sum;
	ull ret = 0;
	if (l == r){
		ret = t[rt].sum;
		if (t[rt].sum == t[rt].nxsum) return ret;
		t[rt].sum = t[rt].nxsum;
		t[rt].nxsum = mul(t[rt].sum, t[rt].sum);
		if (t[rt].sum == t[rt].nxsum) t[rt].f = 1;
		return ret;
	}
	int m = l + r >> 1;
	if (L <= m){
		ret += update(L, R, rt<<1, l, m);
		if (ret >= p) ret -= p;
	}
	if (m < R){
		ret += update(L, R, rt<<1|1, m+1, r);
		if (ret >= p) ret -= p;
	}
	pushup(rt);
	return ret;
}

int T, n, m;
int main()
{
	scanf("%d", &T); int cas = 0;
	while(T--){
		printf("Case #%d:\n", ++cas);
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%llu", &a[i]);
		build(1, 0, n-1);
		ull ans = 0; int L, R;
		while(m--){
			scanf("%d %d", &L, &R);
			ans = (ans + update(L-1, R-1, 1, 0, n-1)) % p;
			printf("%llu\n", ans);
		}
	}
	return 0;
}
