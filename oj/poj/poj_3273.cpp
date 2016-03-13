#include<cstdio>
using namespace std;

int n, m;
int a[100100];
bool ok(int bound)
{
	int sum = 0, cnt = 0;;
	for (int i = 0; i < n; i++)
	{
		if (sum + a[i] <= bound)
		{
			sum += a[i];
		}
		else
		{
			sum = a[i];
			cnt++;
		}
	}
	if (cnt + 1 > m) return false;
	else return true;
}
int main()
{
	int l = 0, r = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > l) l = a[i];
		r += a[i];
	}
	int ans = r;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (ok(mid))
		{
			if (mid < ans)
				ans = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
