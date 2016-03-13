#include<cstdio>
#include<cstring>
#include<algorithm>
int n, m;
int a[10100], sum[10100];
struct tree{
	int sum, lmax, rmax, smax;
} t[10100 << 2];

int max(int a, int b)
{
	return a>b?a:b;
}
void update(tree &x, tree lson, tree rson)
{
	x.sum = lson.sum + rson.sum;
	x.lmax = max(lson.lmax, lson.sum+rson.lmax);
	x.rmax = max(rson.rmax, rson.sum+lson.rmax);
	int tmp = max(lson.smax, rson.smax);
	tmp = max(tmp, lson.rmax+rson.lmax);
	x.smax = tmp;
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
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sum[0] = 0;
		for (int i = 1; i <= n; i++)
			sum[i] = sum[i-1] + a[i];
		build(1, 1, n);
		scanf("%d", &m);
		int x1, y1, x2, y2;
		for (int i = 0; i < m; i++){
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			int ans = 0;
			if (y1 == x2){
//				ans = a[y1];
//				int tmp1 = 0, tmp2 = 0;
//				if (x1 <= y1-1) tmp1 = max(query(x1, y1-1, 1, 1, n).rmax, 0);
//				if (x2+1 <= y2) tmp2 = max(query(x2+1, y2, 1, 1, n).lmax, 0);
//				ans += tmp1 + tmp2;
				ans = query(x1, y1, 1, 1, n).rmax + query(x2, y2, 1, 1, n).lmax - a[y1];
			}
			else if (y1 < x2){
				ans = sum[x2-1] - sum[y1];
				ans += query(x1, y1, 1, 1, n).rmax + query(x2, y2, 1, 1, n).lmax;
			}
			else{
				int tmp = query(x2, y1, 1, 1, n).smax;
				ans = tmp;
				
				tmp = sum[y1-1] - sum[x2];
				tmp += query(x1, x2, 1, 1, n).rmax + query(y1, y2, 1, 1, n).lmax;
				ans = max(tmp, ans);

				tmp = query(x1, x2, 1, 1, n).rmax + query(x2, y1, 1, 1, n).lmax - a[x2];
				ans = max(tmp, ans);

				tmp = query(x2, y1, 1, 1, n).rmax + query(y1, y2, 1, 1, n).lmax - a[y1];
				ans = max(tmp, ans);

			}
			printf("%d\n", ans); 
		}
	}
	return 0;
}
