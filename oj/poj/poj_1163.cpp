#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int a[110][110], dp[110][110];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &a[i][j]);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + a[i][j];
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (dp[n][i] > ans) ans = dp[n][i];
	printf("%d\n", ans);
	return 0;
}
