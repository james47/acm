#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N, V, T;
int dp[1100], v[1100], w[1100];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &V);
		for (int i = 0; i < N; i++)
			scanf("%d", v+i);
		for (int i = 0; i < N; i++)
			scanf("%d", w+i);
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		for (int i = 0; i < N; i++)
			for (int j = V; j >= w[i]; j--){
				int tmp = j - w[i];
				if (dp[tmp] == -1) continue;
				dp[j] = max(dp[j], dp[tmp] + v[i]);
			}
		int ans = 0;
		for (int i = 0; i <= V; i++)
			if (dp[i] > ans) ans = dp[i];
		printf("%d\n", ans);
	}
	return 0;
}
