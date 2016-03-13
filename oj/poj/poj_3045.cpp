#include<cstdio>
#include<algorithm>
using namespace std;

struct cow
{
	int w,s;
}a[50010];
bool cmp(cow a, cow b)
{
	if ((a.w + a.s) > (b.w + b.s))
		return true;
	else	return false;
}
int main()
{
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i].w, &a[i].s);
		sum += a[i].w;
	}
	sort(a, a + n, cmp);
	int ans = -2147483640, tmp;
	for (int i = 0; i < n; i++)
	{
		sum -= a[i].w;
		tmp = sum - a[i].s;
		if (tmp > ans) ans = tmp;
	}
	printf("%d\n", ans);
	return 0;
}
