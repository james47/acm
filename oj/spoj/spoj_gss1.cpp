#include<cstdio>
#include<cstring>
#include<algorithm>
int n, m;
int a[50100];
struct tree{
	int sum, lmax, rmax, smax;
} t[50010 << 2];

int max(int a, int b)
{
	return a>b?a:b;
}
void update(tree &x, tree lson, tree rson)
{
	x.sum = lson.sum + rson.sum;
	x.lmax = max(lson.lmax, lson.sum+rson.lmax);
	x.rmax = max(rson.rmax, rson.sum+lson.rmax);
	int tmp = max(x.lmax, x.rmax);
	tmp = max(tmp, x.sum);
	tmp = max(tmp, lson.smax);
	tmp = max(tmp, rson.smax);
	tmp = max(tmp, lson.rmax+rson.lmax);
	x.smax = tmp;
	//x.smax = max(max(x.sum, max(x.lmax, x.rmax)), max(max((lson.smax, rson.smax), (lson.rmax+rson.lmax))));
}
void build(int x, int l, int r)
{
	if (l == r){
		t[x].sum = t[x].lmax = t[x].rmax = t[x].smax = a[l];
		return;
	}
	int mid = l + r >> 1, lson = x<<1, rson = x<<1|1;
	build(lson, l, mid);
	build(rson, mid+1, r);
	update(t[x], t[lson], t[rson]);
}
tree query(int s, int e, int x, int l, int r)
{
	if (s <= l && r <= e){
	//if (s <= l && r <= e){
		return t[x];
	}
	int mid = l + r >> 1;
	if (e <= mid) return query(s, e, x<<1, l, mid);
	if (s > mid) return query(s, e, x<<1|1, mid+1, r);
	tree p, q, ans;
	p = query(s, mid, x<<1, l, mid);
	q = query(mid+1, e, x<<1|1, mid+1, r);
	update(ans, p, q);
	return ans;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build(1, 1, n);

//	for (int i = 1; i <= 10; i++)
//		printf("%d %d %d %d %d\n", i, t[i].sum, t[i].lmax, t[i].rmax, t[i].smax);

	scanf("%d", &m);
	int x, y;
	for (int i = 0; i < m; i++){
		scanf("%d %d", &x, &y);
		printf("%d\n", query(x, y, 1, 1, n).smax);
	}
	return 0;
}
