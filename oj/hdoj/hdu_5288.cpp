#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int mod = (int)1e9+7;
int n;
int last[10100], a[101000], l[101000], r[101000];
int main()
{
	while(scanf("%d", &n) != EOF){
		for (int i = 1; i <= n; i++) scanf("%d", a+i);
		long long ans = 0;
		memset(last, 0, sizeof(last));
		for (int i = 1; i <= n; i++){
			l[i] = 0;
			for (int j = 1; j * j <= a[i]; j++)
				if (a[i] % j == 0){
					l[i] = max(l[i], last[j]);
					l[i] = max(l[i], last[a[i]/j]);
				}
			last[a[i]] = i;
		}
		memset(last, 0, sizeof(last));
		for (int i = n; i >= 1; i--){
			r[i] = n+1;
			for (int j = 1; j * j <= a[i]; j++)
				if (a[i] % j == 0){
					if (last[j]) r[i] = min(r[i], last[j]);
					if (last[a[i]/j]) r[i] = min(r[i], last[a[i]/j]);
				}
			last[a[i]] = i;
		}
		for (int i = 1; i <= n; i++){
			ans += (long long)(i - l[i]) * (r[i] - i);
			ans %= mod;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
