#include<cstdio>
#include<cstring>
using namespace std;

int n, m;
long long sum[100100];
int ll[100100], dam[100100];
int main()
{
	while(scanf("%d", &n) && n)
	{
		scanf("%d", &m);
		int l, r, d;
		memset(ll, 0, sizeof(ll));
		for (int i = 0; i < m; i++){
			scanf("%d %d %d", &l, &r, &d);
			ll[l] += d; ll[r+1] += -d;
		}
		dam[0] = 0; sum[n+1] = 0;
		for (int i = 1; i <= n; i++) dam[i] = dam[i-1] + ll[i];
		for (int i = n; i >= 1; i--) sum[i] = sum[i+1] + dam[i];
		int k, ans = 0, pos;
		long long h;
		scanf("%d", &k);
		for (int i = 0; i < k; i++){
			scanf("%lld %d", &h, &pos);
			if (sum[pos] < h) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
