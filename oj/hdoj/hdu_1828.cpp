/*************************************************************************
    > File Name: hdu_1828.cpp
    > Author: james47
    > Mail: 
    > Created Time: Fri Jul 31 15:12:41 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 5010;
struct seg{
	int lx, rx, y, f;
	seg(){}
	seg(int _lx, int _rx, int _y, int _f):lx(_lx), rx(_rx), y(_y), f(_f){}
} s[maxn<<1];
struct tree{
	int f, sum, num, lb, rb;
} t[maxn << 4];
int xx[maxn << 1];

bool cmp(seg a, seg b){
	if (a.y == b.y) return a.f > b.f;
	return a.y < b.y;
}

void build(int rt, int l, int r){
	memset(t+rt, 0, sizeof(t[rt]));
	if (l == r) return;
	int m = l + r >> 1;
	build(rt<<1, l, m);
	build(rt<<1|1, m+1, r);
}


void pushup(int rt, int l, int r){
	if (t[rt].f){
		t[rt].sum = xx[r+1] - xx[l];
		t[rt].num = 2;
		t[rt].lb = t[rt].rb = 1;
	}
	else if (l == r){
		t[rt].num = t[rt].sum = t[rt].lb = t[rt].rb = 0;
	}
	else{
		t[rt].sum = t[rt<<1].sum + t[rt<<1|1].sum;
		t[rt].num = t[rt<<1].num + t[rt<<1|1].num;
		t[rt].lb = t[rt<<1].lb; t[rt].rb = t[rt<<1|1].rb;
		if (t[rt<<1].rb && t[rt<<1|1].lb) t[rt].num -= 2;
	}
}

void update(int L, int R, int v, int rt, int l, int r){
	if (L <= l && r <= R){
		t[rt].f += v;
		pushup(rt, l, r);
		return; 
	}
	int m = l + r >> 1;
	if (L <= m) update(L, R, v, rt<<1, l, m);
	if (m < R) update(L, R, v, rt<<1|1, m+1, r);
	pushup(rt, l, r);
}

int n, size, cnt;
int main()
{
	while(scanf("%d", &n) != EOF){
		int a, b, c, d;
		size = 0, cnt = 0;
		for (int i = 0; i < n; i++){
			scanf("%d %d %d %d", &a, &b, &c, &d);
			s[size++] = seg(a, c, b, 1);
			s[size++] = seg(a, c, d, -1);
			xx[cnt++] = a; xx[cnt++] = c;
			
		}
		sort(xx, xx+cnt);
		cnt = unique(xx, xx+cnt) - xx;
		for (int i = 0; i < size; i++){
			s[i].lx = lower_bound(xx, xx+cnt, s[i].lx) - xx;
			s[i].rx = lower_bound(xx, xx+cnt, s[i].rx) - xx;
		}
		sort(s, s+size, cmp);
		build(1, 0, cnt-1);
		int o, ans = 0;
		for (int i = 0; i < size; i++){
			o = t[1].sum;//query(0, cnt-1, 1, 0, cnt-1);
			update(s[i].lx, s[i].rx-1, s[i].f, 1, 0, cnt-2);
			ans += abs(t[1].sum - o);
			if (i+1 < size) ans += t[1].num * (s[i+1].y - s[i].y);
		}
		printf("%d\n", ans);
	}
	return 0;
}
