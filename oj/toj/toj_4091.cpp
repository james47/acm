#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, V, w[110], v[110], dp[1100];
int main()
{
	while(scanf("%d %d", &n, &V) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) scanf("%d", w+i);
		for (int i = 0; i < n; i++) scanf("%d", v+i);
		for (int i = 0; i < n; i++)
			for (int j = w[i]; j <= V; j++)
				dp[j] = max(dp[j-w[i]] + v[i], dp[j]);
		int ans = 0;
		for (int i = 0; i <= V; i++) if (dp[i] > ans) ans = dp[i];
		printf("%d\n", ans);
	}
	return 0;
}
