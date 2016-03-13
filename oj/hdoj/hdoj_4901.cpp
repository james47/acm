#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const long long mo = (long long)1e9 + 7;
int n, T;
int a[1100];
long long f[1100][1100], g[1100][1100], h[1100][1100];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", a+i);
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		memset(h, 0, sizeof(h));
		for (int i = 0; i < n-1; i++){
			f[i][a[i]] ++;
			if (i == 0){
				g[i][a[i]] ++;
				continue;
			}
			for (int j = 0; j < 1024; j++)
				f[i][j] = (f[i][j] + g[i-1][j^a[i]]) % mo;
			for (int j = 0; j < 1024; j++)
				g[i][j] = (g[i-1][j] + f[i][j]) % mo;
		}
		for (int i = n-1; i > 0; i--){
			h[i][a[i]] ++;
			if (i == n-1) continue;
			for (int j = 0; j < 1024; j++)
				h[i][j&a[i]] = (h[i][j&a[i]] + h[i+1][j]) % mo;
			for (int j = 0; j < 1024; j++)
				h[i][j] = (h[i][j] + h[i+1][j]) % mo;
		}
		long long ans = 0;
		for (int i = 0; i < n-1; i++)
			for (int j = 0; j < 1024; j++)
				if (f[i][j] > 0)
					ans = (ans + f[i][j] * h[i+1][j]) % mo;
		printf("%lld\n", ans);
	}
	return 0;
}
