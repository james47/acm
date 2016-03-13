#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T;
int a[40];
long long dp[40][3];
long long n;
int main()
{
	memset(dp, 0, sizeof(dp));
	dp[0][2] = 1;
	for (int i = 1; i <= 24; i++){
		dp[i][0] = dp[i-1][0] * 10 + dp[i-1][1];
		dp[i][1] = dp[i-1][1] + dp[i-1][2];
		dp[i][2] = dp[i-1][1] * 8 + dp[i-1][2] * 9;
	}
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld", &n);
		int len = 0;
		while(n){
			a[len++] = n % 10;
			n = n / 10;
		}
		a[len] = 0;
		long long ans = 0;
		for (int i = len-1; i+1; i--){
			if (a[i] == 0) continue;
			ans = ans + dp[i][0] * a[i];
			if (a[i] > 4) ans = ans + dp[i][1];
			if (a[i+1] == 4 && a[i] == 9){
				long long tmp = 0;
				for (int j = i-1; j+1; j--)
					tmp = tmp * 10 + a[j];
				ans = ans + tmp + 1;
				break;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
