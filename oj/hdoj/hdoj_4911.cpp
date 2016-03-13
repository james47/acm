#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = (int)1e5 + 10;
struct node{
	int v, p;
} a[maxn];
int n, k;
long long sum[maxn];
int b[maxn];
int lowbit(int x)
{
	return x & -x;
}
void update(int x, int val)
{
	for (int i = x; i <= maxn; i += lowbit(i))
		sum[i] += val;
}
int query(int x)
{
	int ans = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		ans += sum[i];
	return ans;
}
bool cmp(node a, node b)
{
	return a.v < b.v;
}
int main()
{
	while(scanf("%d %d", &n, &k) != EOF)
	{
		for (int i = 0; i < n; i++){
			scanf("%d", &a[i].v);
			a[i].p = i;
		}
		sort(a, a+n, cmp);
		int cnt = 2; b[a[0].p] = cnt;
		for (int i = 1; i < n; i++)
			if (a[i].v == a[i-1].v) b[a[i].p] = cnt;
			else b[a[i].p] = ++ cnt;
		long long ans = 0;
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < n; i++){
			ans = ans + i - query(b[i]);
			update(b[i], 1);
		}
		ans = ans - k;
		if (ans < 0) ans = 0;
		printf("%lld\n", ans);
	}
	return 0;
}
