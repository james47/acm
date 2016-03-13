/*************************************************************************
    > File Name: e.cpp
    > Author: james47
    > Mail: 
    > Created Time: Wed Jul 15 18:36:55 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = (int)1e5 + 100;
int n, q, st, ed, ty, sc, ec, dir, fr, cnt;
int sum[26][maxn << 2], c[26][maxn << 2], f[26][maxn << 2], fs[26][maxn << 2];
char s[maxn];

void pushdown(int id, int rt, int l, int r){
	int m = l + r >> 1;
	if (c[id][rt]){
		c[id][rt<<1] = c[id][rt<<1|1] = 1;
		c[id][rt] = 0;
		sum[id][rt<<1] = sum[id][rt<<1|1] = f[id][rt<<1] = f[id][rt<<1|1] = fs[id][rt<<1] = fs[id][rt<<1|1] = 0;
	}
	if (f[id][rt]){
		f[id][rt<<1] = f[id][rt<<1|1] = 1;
		fs[id][rt<<1] += fs[id][rt]; fs[id][rt<<1|1] += fs[id][rt];
		sum[id][rt<<1] += fs[id][rt] * (m - l + 1); sum[id][rt<<1|1] += fs[id][rt] * (r - m);
		f[id][rt] = fs[id][rt] = 0;
	}
}

void pushup(int id, int rt, int l, int r){
	sum[id][rt] = sum[id][rt<<1] + sum[id][rt<<1|1];
}

int query(int id, int L, int R, int rt, int l, int r){
	if (R < L) return 0;
	//printf("%d %d\n", l, r);
	//if (c[id][rt]) return 0;
	if (L <= l && r <= R){
		return sum[id][rt];
	}
	int ret = 0;
	int m = l + r >> 1;
	pushdown(id, rt, l, r);
	if (L <= m) ret += query(id, L, R, rt<<1, l, m);
	if (m < R) ret += query(id, L, R, rt<<1|1, m+1, r);
	pushup(id, rt, l, r);
	return ret;
}

void clear(int id, int L, int R, int rt, int l, int r){
	if (R < L) return;
	//printf("%d %d\n", l, r);
	if (L <= l && r <= R){
		c[id][rt] = 1;
		sum[id][rt] = f[id][rt] = fs[id][rt] = 0;
		return;
	}
	int m = l + r >> 1;
	pushdown(id, rt, l, r);
	if (L <= m) clear(id, L, R, rt<<1, l, m);
	if (m < R) clear(id, L, R, rt<<1|1, m+1, r);
	pushup(id, rt, l, r);
}

void insert(int id, int L, int R, int v, int rt, int l, int r){
	if (R < L) return;
	if (L <= l && r <= R){
		c[id][rt] = 0;
		sum[id][rt] += v * (r - l + 1);
		f[id][rt] = 1; fs[id][rt] += v;
		return;
	}
	int m = l + r >> 1;
	pushdown(id, rt, l, r);
	if (L <= m) insert(id, L, R, v, rt<<1, l, m);
	if (m < R) insert(id, L, R, v, rt<<1|1, m+1, r);
	pushup(id, rt, l, r);
}

void debug(){
	int l, r, v, n, type;
	scanf("%d", &n);
	while(scanf("%d", &type)){
		if (type == 0) return;
		if (type == 1){
			scanf("%d %d %d", &l, &r, &v);
			insert(0, l, r, v, 1, 1, n);
		}
		if (type == 2){
			scanf("%d %d", &l, &r);
			clear(0, l, r, 1, 1, n);
		}
		if (type == 3){
			scanf("%d %d", &l, &r);
			printf("%d\n", query(0, l, r, 1, 1, n));
		}
	}
}
int main()
{
	//debug();
	scanf("%d %d", &n, &q);
	scanf("%s", s);
	memset(sum, 0, sizeof(sum));
	memset(f, 0, sizeof(f));
	memset(fs, 0, sizeof(fs));
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++) insert(s[i]-'a', i, i, 1, 1, 0, n-1);
	for (int i = 0; i < q; i++){
		scanf("%d %d %d", &st, &ed, &ty);
		st --, ed --;
		fr = st;
		if (ty == 1) dir = 1, sc = 0, ec = 26;
		else dir = -1, sc = 25, ec = -1;
		for (int j = sc; j != ec; j += dir){
			cnt = query(j, st, ed, 1, 0, n-1);
			if (cnt){
				clear(j, st, ed, 1, 0, n-1);
				insert(j, fr, fr+cnt-1, 1, 1, 0, n-1);
				fr += cnt;
			}	
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 26; j++){
			if (query(j, i, i, 1, 0, n-1)){
				s[i] = j + 'a';
				break;
			}
		}
	}
	printf("%s\n", s);
	return 0;
}
