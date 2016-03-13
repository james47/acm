#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct tree{
	int maxn;
	bool flag;
}t[101000 << 2]; 
int T, n, q;
int a[101000];
void pushup(int x)
{
	t[x].maxn = max(t[x<<1].maxn, t[x<<1|1].maxn);
}
void pushdown(int x)
{
	if (t[x].flag){
		t[x].flag = false;
		t[x<<1].maxn = t[x<<1|1].maxn = t[x].maxn;
		t[x<<1].flag = t[x<<1|1].flag = true;
	}
}
void build(int x, int l, int r)
{
	t[x].flag = false;
	if (l == r){
		t[x].flag = true;
		t[x].maxn = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	pushup(x);
}
void update(int x, int l, int r, int s, int e, int v)
{
	if (s <= l && r <= e){
		t[x].flag = true;
		t[x].maxn = v;
		return;
	}
	pushdown(x);
	int mid = l + r >> 1;
	if (s <= mid)
		update(x<<1, l, mid, s, e, v);
	if (e > mid)
		update(x<<1|1, mid+1, r, s, e, v);
	pushup(x);
}
void trans(int x, int l, int r, int s, int e, int v)
{
	if (t[x].maxn <= v) return;
	if (s <= l && r <= e && t[x].flag){
		t[x].maxn = __gcd(t[x].maxn, v);
		return;
	}
	if (l == r){
		t[x].maxn = __gcd(t[x].maxn, v);
		return;
	}
	pushdown(x);
	int mid = l + r >> 1;
	if (s <= mid)
		trans(x<<1, l, mid, s, e, v);
	if (e > mid)
		trans(x<<1|1, mid+1, r, s, e, v);
	pushup(x);
}
int query(int x, int l, int r, int p)
{
	if (t[x].flag) return t[x].maxn;
	int mid = l + r >> 1;
	if (p <= mid) return query(x<<1, l, mid, p);
	else return query(x<<1|1, mid+1, r, p);
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", a+i);
		build(1, 1, n);
		scanf("%d", &q);
		int type, l, r, x;
		for (int i = 0; i < q; i++){
			scanf("%d %d %d %d", &type, &l, &r, &x);
			if (type == 1)
				update(1, 1, n, l, r, x);
			else
				trans(1, 1, n, l, r, x);
		}
		for (int i = 1; i <= n; i++)
			printf("%d ", query(1, 1, n, i));
		puts("");
	}
	return 0;
}
