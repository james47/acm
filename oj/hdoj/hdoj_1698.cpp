#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 100010;
int flag[maxn * 4], sum[maxn * 4];
int n, q;
void pushdown(int x, int l, int r)
{
	int mid = l + r >> 1;
	if (flag[x]){
		flag[x<<1] = flag[x];
		flag[x<<1|1] = flag[x];
		sum[x<<1] = flag[x] * (mid - l + 1);
		sum[x<<1|1] = flag[x] * (r - mid);
		flag[x] = 0;
	}
}
void build(int x, int l, int r)
{
	if (l == r){
		sum[x] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	sum[x] = sum[x<<1] + sum[x<<1|1];
}
void update(int x, int l, int r, int s, int e, int d)
{
	if (s <= l && r <= e){
		flag[x] = d;
		sum[x] = d * (r - l + 1);
		return;
	}
	pushdown(x, l, r);
	int mid = l + r >> 1;
	if (s <= mid) update(x<<1, l, mid, s, e, d);
	if (mid < e) update(x<<1|1, mid+1, r, s, e, d);
	sum[x] = sum[x<<1] + sum[x<<1|1];
}
int main()
{
	int T, cas = 0;
	scanf("%d", &T);
	while(T--)
	{
		memset(flag, 0, sizeof(flag));
		scanf("%d %d", &n, &q);
		build(1, 1, n);
		int x, y, z;
		for (int i = 0; i < q; i++){
			scanf("%d %d %d", &x, &y, &z);
			update(1, 1, n, x, y, z);
		}
		cas++;
		printf("Case %d: The total value of the hook is %d.\n", cas, sum[1]);
	}
}
