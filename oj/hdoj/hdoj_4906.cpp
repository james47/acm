#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;

const int mod = (int)1e9+7;
int T, N, K, L, MAX, extra;
long long dp[(1<<20)+10];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &N, &K, &L);
		memset(dp, 0, sizeof(dp));
		if (L > K){
			extra = L - K;
			L = K;
		}
		else extra = 0;
		dp[0] = 1;
		MAX = (1 << K) - 1;
		for (int i = 1; i <= N; i++)
			for (int j = MAX; j >= 0; j--){
				if (dp[j] == 0) continue;
				long long tmp = dp[j];
				for (int k = 1; k <= L; k++){
					int to = j | 1<<(k-1) | ((j<<k)&MAX);
					dp[to] += tmp;
					if (dp[to] >= mod) dp[to] -= mod;
				}
				//if (dp[j] != tmp) printf("%d %lld %lld\n", j, dp[j], tmp);
				dp[j] = (dp[j] + tmp * extra) % mod;
			}
		long long ans = 0;
		for (int i = 1 << (K-1); i <= MAX; i++){
			ans += dp[i];
			if (ans >= mod) ans -= mod;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
