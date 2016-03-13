#include<cstdio>
#include<cstring>
using namespace std;

typedef long long LL;
const int maxn = 100010;
int n;
int f[maxn+100], a[maxn+100], b[maxn+100];
int main()
{
	while(scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int i = 0; i <= maxn; i++) f[i] = i;
		for (int i = 0; i < n; i++){
			int x = a[i];
			b[i] = f[x];
			for (int j = 1; j * j <= x; j++)
				if (x % j == 0) f[x/j] = f[j] = x;
		}
		LL ans = 0;
		for (int i = 0; i <= maxn; i++) f[i] = i;
		for (int i = n-1; i >= 0; i--){
			int x = a[i];
			ans += (LL)f[x] * b[i];
			for (int j = 1; j * j <= x; j++)
				if (x % j == 0) f[x/j] = f[j] = x;
		}
		//printf("%I64d\n", ans);
		printf("%lld\n", ans);
	}
	return 0;
}
