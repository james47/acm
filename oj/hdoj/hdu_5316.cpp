/*************************************************************************
    > File Name: 011.cpp
    > Author: james47
    > Mail: 
    > Created Time: Tue Jul 28 18:11:19 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 100010;
const ll inf = (ll)1e15;
struct tree{
	ll s[4];
	void init(){
		for (int i = 0; i < 4; i++) s[i] = -inf;
	}
} p[maxn << 2];
int a[maxn];

void pushup(int rt){
	int ls = rt<<1, rs = rt<<1|1;
	p[rt].s[0] = max(p[ls].s[0], p[rs].s[0]);
	if (p[ls].s[0] != -inf && p[rs].s[2] != -inf) p[rt].s[0] = max(p[rt].s[0], p[ls].s[0] + p[rs].s[2]);
	if (p[ls].s[1] != -inf && p[rs].s[0] != -inf) p[rt].s[0] = max(p[rt].s[0], p[ls].s[1] + p[rs].s[0]);


	p[rt].s[1] = max(p[ls].s[1], p[rs].s[1]);
	if (p[ls].s[0] != -inf && p[rs].s[3] != -inf) p[rt].s[1] = max(p[rt].s[1], p[ls].s[0] + p[rs].s[3]);
	if (p[ls].s[1] != -inf && p[rs].s[1] != -inf) p[rt].s[1] = max(p[rt].s[1], p[ls].s[1] + p[rs].s[1]);


	p[rt].s[2] = max(p[ls].s[2], p[rs].s[2]);
	if (p[ls].s[2] != -inf && p[rs].s[2] != -inf) p[rt].s[2] = max(p[rt].s[2], p[ls].s[2] + p[rs].s[2]);
	if (p[ls].s[3] != -inf && p[rs].s[0] != -inf) p[rt].s[2] = max(p[rt].s[2], p[ls].s[3] + p[rs].s[0]);


	p[rt].s[3] = max(p[ls].s[3], p[rs].s[3]);
	if (p[ls].s[3] != -inf && p[rs].s[1] != -inf) p[rt].s[3] = max(p[rt].s[3], p[ls].s[3] + p[rs].s[1]);
	if (p[ls].s[2] != -inf && p[rs].s[3] != -inf) p[rt].s[3] = max(p[rt].s[3], p[ls].s[2] + p[rs].s[3]);

}


tree merge(tree ls, tree rs){
	tree rt;
	for (int i = 0; i < 4; i++) rt.s[i] = -inf;
	rt.s[0] = max(ls.s[0], rs.s[0]);
	if (ls.s[0] != -inf && rs.s[2] != -inf) rt.s[0] = max(rt.s[0], ls.s[0] + rs.s[2]);
	if (ls.s[1] != -inf && rs.s[0] != -inf) rt.s[0] = max(rt.s[0], ls.s[1] + rs.s[0]);


	rt.s[1] = max(ls.s[1], rs.s[1]);
	if (ls.s[0] != -inf && rs.s[3] != -inf) rt.s[1] = max(rt.s[1], ls.s[0] + rs.s[3]);
	if (ls.s[1] != -inf && rs.s[1] != -inf) rt.s[1] = max(rt.s[1], ls.s[1] + rs.s[1]);


	rt.s[2] = max(ls.s[2], rs.s[2]);
	if (ls.s[2] != -inf && rs.s[2] != -inf) rt.s[2] = max(rt.s[2], ls.s[2] + rs.s[2]);
	if (ls.s[3] != -inf && rs.s[0] != -inf) rt.s[2] = max(rt.s[2], ls.s[3] + rs.s[0]);


	rt.s[3] = max(ls.s[3], rs.s[3]);
	if (ls.s[3] != -inf && rs.s[1] != -inf) rt.s[3] = max(rt.s[3], ls.s[3] + rs.s[1]);
	if (ls.s[2] != -inf && rs.s[3] != -inf) rt.s[3] = max(rt.s[3], ls.s[2] + rs.s[3]);
	return rt;
}

void build(int rt, int l, int r){
	for (int i = 0; i < 4; i++) p[rt].s[i] = -inf;
	if (l == r){
		if (l&1) p[rt].s[3] = a[l];
		else p[rt].s[0] = a[l];
		return;
	}
	int m = l + r >> 1;
	build(rt<<1, l, m);
	build(rt<<1|1, m+1, r);
	pushup(rt);
}
void update(int pos, int x, int rt, int l, int r){
	if (l == r){
		a[pos] = x;
		if (pos&1) p[rt].s[3] = a[pos];
		else p[rt].s[0] = a[l];
		return;
	}
	int m = l + r >> 1;
	if (pos <= m) update(pos, x, rt<<1, l, m);
	else update(pos, x, rt<<1|1, m+1, r);
	pushup(rt);
}

tree query(int L, int R, int rt, int l, int r){
	if (L <= l && r <= R) return p[rt];
	int m = l + r >> 1;
	tree ll, rr;
	ll.init(); rr.init();
	if (L <= m) ll = query(L, R, rt<<1, l, m);
	if (m < R) rr = query(L, R, rt<<1|1, m+1, r);
	return merge(ll, rr);
}

ll work(int L, int R, int rt, int l, int r){
	tree tmp = query(L, R, rt, l, r);
	ll ret = -inf;
	for (int i = 0; i < 4; i++)
		ret = max(ret, tmp.s[i]);
	return ret;
}

int T, n, m;
int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%d", a+i);
		build(1, 0, n-1);
		int type, x, y;
		while(m--){
			scanf("%d %d %d", &type, &x, &y);
			if (type == 0) printf("%lld\n", work(x-1, y-1, 1, 0, n-1));
			else update(x-1, y, 1, 0, n-1);
		}
	}
	return 0;
}
