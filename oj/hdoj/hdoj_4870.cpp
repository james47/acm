#include<cstdio>
#include<cstring>
using namespace std;

double dp[30], ans[30][30];
double p;
int main()
{
	while(scanf("%lf", &p) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		memset(ans, 0, sizeof(ans));
		dp[0] = 1/p; dp[1] = 1/p + (1-p)/p/p;
		for (int i = 2; i <= 20; i++)
			dp[i] = 1/p + (1-p)/p*(dp[i-2]+dp[i-1]);
		ans[0][0] = 0; ans[1][0] = dp[0]; ans[1][1] = 2*dp[0];
		for (int i = 1; i <= 20; i++){
			ans[i][i] = ans[i][i-1] + dp[i-1];
			ans[i+1][i] = ans[i][i] + dp[i];
		}
		printf("%.6lf\n", ans[20][19]);
	}
	return 0;
}
