#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct tree{
	int f, m[11];
} p[100000];
int need[20];
int T, n, k, q, cas;


void pushup(int rt){
	int ls = rt<<1, rs = rt<<1|1;
	for (int i = 1; i <= k; i++)
		p[rt].m[i] = max(p[ls].m[i], p[rs].m[i]);
}
void pushdown(int rt, int l, int r){
	if (p[rt].f){
		int ls = rt<<1, rs = rt<<1|1, m = l + r >> 1;
		p[ls].f += p[rt].f; p[rs].f += p[rt].f;
		for (int i = k; i > 0; i--){
			if (p[ls].m[i] != -1) p[ls].m[i] += p[rt].f * i;
			if (p[rs].m[i] != -1) p[rs].m[i] += p[rt].f * i;
		}
		p[rt].f = 0;
	}
}
void build(int rt, int l, int r){
	p[rt].f = 0;
	for (int i = 2; i <= k; i++) p[rt].m[i] = -1;
	p[rt].m[1] = 0;
	if (l == r) return;
	int m = l + r >> 1;
	build(rt<<1, l, m);
	build(rt<<1|1, m+1, r);
}
void levelup(int lv, int rt, int l, int r){
	if (l == r){
		p[rt].m[lv+1] = p[rt].m[lv];
		p[rt].m[lv] = -1;
		return;
	}
	int ls = rt<<1, rs = rt<<1|1, m = l + r >> 1;
	pushdown(rt, l, r);
	if (p[ls].m[lv] >= need[lv]) levelup(lv, ls, l, m);
	if (p[rs].m[lv] >= need[lv]) levelup(lv, rs, m+1, r);
	p[rt].m[lv] = max(p[ls].m[lv], p[rs].m[lv]);
	p[rt].m[lv+1] = max(p[ls].m[lv+1], p[rs].m[lv+1]);
}
int query(int L, int R, int rt, int l, int r){
	if (L <= l && r <= R){
		for (int i = k; i > 0; i--)
			if (p[rt].m[i] != -1){
				return p[rt].m[i];
			}
		return 0;
	}
	int m = l + r >> 1, ret = 0;
	pushdown(rt, l, r);
	if (L <= m) ret = max(ret, query(L, R, rt<<1, l, m));
	if (m < R) ret = max(ret, query(L, R, rt<<1|1, m+1, r));
	pushup(rt);
	return ret;
}

void modify(int L, int R, int E, int rt, int l, int r){
	if (L <= l && r <= R){
		p[rt].f += E;
		int flag = 0;
		for (int i = k; i > 0; i--){
			if (p[rt].m[i] != -1) p[rt].m[i] += E * i;
		}
		for (int i = 1; i < k; i++)
			if (p[rt].m[i] >= need[i]) levelup(i, rt, l, r);
		return;
	}
	int m = l + r >> 1;
	pushdown(rt, l, r);
	if (L <= m) modify(L, R, E, rt<<1, l, m);
	if (m < R) modify(L, R, E, rt<<1|1, m+1, r);
	pushup(rt);
}
char buf[10];
int main()
{
	scanf("%d", &T);
	cas = 0;
	while(T--){
		printf("Case %d:\n", ++cas);
		scanf("%d %d %d", &n, &k, &q);
		for (int i = 1; i < k; i++) scanf("%d", need+i);
		need[k] = 2147483600;
		build(1, 0, n-1);
		while(q--){
			scanf("%s", buf);
			int L, R, E;
			if (buf[0] == 'Q'){
				scanf("%d %d", &L, &R);
				printf("%d\n", query(L-1, R-1, 1, 0, n-1));
			}
			else{
				scanf("%d %d %d", &L, &R, &E);
				modify(L-1, R-1, E, 1, 0, n-1);
			}
		}
		puts("");
	}
	return 0;
}
