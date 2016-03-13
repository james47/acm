#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 200010;
char c[10];
int n, m;
int h[maxn*4], a[maxn];
void build(int x, int l, int r)
{
	if (l == r){
		h[x] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	h[x] = max(h[x<<1], h[x<<1|1]);
}
void update(int p, int s, int x, int l, int r)
{
	if (l == r){
		h[x] = s;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid) update(p, s, x << 1, l, mid);
	if (mid < p) update(p, s, x<<1|1, mid+1, r);
	h[x] = max(h[x<<1], h[x<<1|1]);
}
int query(int s, int e, int x, int l, int r)
{
	if (e < l || r < s) return -1;
	if (s <= l && r <= e)
		return h[x];
	int mid = l + r >> 1;
	return max(query(s, e, x<<1, l, mid), query(s, e, x<<1|1, mid+1, r));
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		build(1, 1, n);
		int x, y;
		for (int i = 0; i < m; i++){
			scanf("%s %d %d", c, &x, &y);
			if (c[0] == 'Q')
				printf("%d\n", query(x, y, 1, 1, n));
			else
				update(x, y, 1, 1, n);
		}
	}
	return 0;
}
