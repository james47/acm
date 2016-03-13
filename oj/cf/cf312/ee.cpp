/*************************************************************************
    > File Name: ee.cpp
    > Author: james47
    > Mail: 
    > Created Time: Thu Jul 16 09:27:54 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = (int)1e5 + 100;
int n, q;
int sum[26][maxn << 2], f[26][maxn << 2];
char s[maxn];

void pushup(int id, int rt){
	sum[id][rt] = sum[id][rt<<1] + sum[id][rt<<1|1];
}
void pushdown(int id, int rt, int l, int r){
	if (f[id][rt] != -1){
		int m = l + r >> 1;
		f[id][rt<<1] = f[id][rt<<1|1] = f[id][rt];
		sum[id][rt<<1] = f[id][rt] * (m - l + 1);
		sum[id][rt<<1|1] = f[id][rt] * (r - m);
		f[id][rt] = -1;
	}
}
void build(int rt, int l, int r){
	if (l == r){
		for (int i = 0; i < 26; i++) sum[i][rt] = 0;
		sum[s[l]-'a'][rt] = 1;
		return;
	}
	int m = l + r >> 1;
	build(rt<<1, l, m);
	build(rt<<1|1, m+1, r);
	for (int i = 0; i < 26; i++) pushup(i, rt);
}
int query(int id, int L, int R, int rt, int l, int r){
	// printf("query id %d L %d R %d rt %d l %d r %d\n", id, L, R, rt, l, r);
	if (L <= l && r <= R) return sum[id][rt];
	int m = l + r >> 1;
	int ret = 0;
	pushdown(id, rt, l, r);
	if (L <= m) ret += query(id, L, R, rt<<1, l, m);
	if (m < R) ret += query(id, L, R, rt<<1|1, m+1, r);
	pushup(id, rt);
	return ret;
}
void update(int id, int L, int R, int v, int rt, int l, int r){
//////////////////	printf("update id %d L %d R %d v %d rt %d l %d r %d\n", id, L, R, v, rt, l, r);
	if (L <= l && r <= R){
		f[id][rt] = v;
		sum[id][rt] = v * (r - l + 1);
		return;
	}
	int m = l + r >> 1;
	pushdown(id, rt, l, r);
	if (L <= m) update(id, L, R, v, rt<<1, l, m);
	if (m < R) update(id, L, R, v, rt<<1|1, m+1, r);
	pushup(id, rt);
}
int main()
{
	scanf("%d %d", &n, &q);
	scanf("%s", s);
	memset(f, -1, sizeof(f));
	build(1, 0, n-1);
	int st, ed, ty;
	while(q--){
		scanf("%d %d %d", &st, &ed, &ty);
		st --, ed --;
		int se, dir, time = 26, pos = st;
		if (ty == 1) se = 0, dir = 1;
		else se = 25, dir = -1;
		for (; time > 0; se += dir, time --){
			int cnt = query(se, st, ed, 1, 0, n-1);
			if (cnt){
				update(se, st, ed, 0, 1, 0, n-1);
				update(se, pos, pos+cnt-1, 1, 1, 0, n-1);
				pos += cnt;
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 26; j++){
			if (query(j, i, i, 1, 0, n-1)){
				s[i] = j + 'a';
				break;
			}
		}
	printf("%s", s);
	return 0;
}
