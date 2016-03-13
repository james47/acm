#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct T{
	long long sum, sum1;
	bool flag;
}t[100100 << 2];
int n, m;
int c, x, y;
long long f[100];
void pushup(int x)
{
	int ls = x << 1, rs = x << 1 | 1;
	t[x].sum = t[ls].sum + t[rs].sum;
	t[x].sum1 = t[ls].sum1 + t[rs].sum1;
}
void pushdown(int x)
{
	if (t[x].flag){
		t[x<<1].sum = t[x<<1].sum1;
		t[x<<1].flag = true;
		t[x<<1|1].sum = t[x<<1|1].sum1;
		t[x<<1|1].flag = true;
		t[x].flag = false;
	}
}
void build(int x, int l, int r)
{
	t[x].flag = false;
	if (l == r){
		t[x].flag = t[x].sum = 0;
		t[x].sum1 = 1;
		return;
	}
	int mid = l + r >> 1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	pushup(x);
}
void add(int x, int l, int r, int p, long long val)
{
	if (l == r){
		t[x].sum += val;
		if (t[x].sum >= f[91])
			t[x].sum1 = f[91];
		else if (t[x].sum <= 1)
			t[x].sum1 = 1;
		else{
			long long * p = upper_bound(f, f+92, t[x].sum);
			if (t[x].sum - *(p-1) <= *p - t[x].sum)
				t[x].sum1 = *(p-1);
			else
				t[x].sum1 = *p;
		}
		return;
	}
	int mid = l + r >> 1;
	pushdown(x);
	if (p <= mid)
		add(x<<1, l, mid, p, val);
	if (p > mid)
		add(x<<1|1, mid+1, r, p, val);
	pushup(x);
}
void tra(int x, int l, int r, int s, int e)
{
	if (l == r){
		t[x].sum = t[x].sum1;
		return;
	}
	if (s <= l && r <= e){
		t[x].flag = true;
		t[x].sum = t[x].sum1;
		return;
	}
	int mid = l + r >> 1;
	pushdown(x);
	if (s <= mid)
		tra(x<<1, l, mid, s, e);
	if (mid < e)
		tra(x<<1|1, mid+1, r, s, e);
	pushup(x);
}
long long query(int x, int l, int r, int s, int e)
{
	if (l == r)
		return t[x].sum;
	if (s <= l && r <= e)
		return t[x].sum;
	long long tmp = 0;
	int mid = l + r >> 1;
	pushdown(x);
	if (s <= mid)
		tmp += query(x<<1, l, mid, s, e);
	if (mid < e)
		tmp += query(x<<1|1, mid+1, r, s, e);
	pushup(x);
	return tmp;
}
int main()
{
	f[0] = 1; f[1] = 1;
	for (int i = 2; i <= 91; i++)
		f[i] = f[i-1] + f[i-2];
	while(scanf("%d %d", &n, &m) != EOF)
	{
		build(1, 1, n);
		while(m--){
			scanf("%d %d %d", &c, &x, &y);
			if (c == 1) add(1, 1, n, x, (long long)y);
			if (c == 2) printf("%lld\n", query(1, 1, n, x, y));
			if (c == 3) tra(1, 1, n, x, y);
		}
	}
	return 0;
}
