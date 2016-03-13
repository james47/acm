#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int mod = 998244353;
int n, cnt[2050];
long long dp[2050], inv[2050], c[15][2050];

int read()
{
	int ans = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans;
}
void init()
{
	inv[1] = 1;
	for (int i = 2; i <= 2048; i++) inv[i] = inv[mod%i] * (mod - mod/i) % mod;
}
void getcom(int i, int n)
{
	int lim = min(n, 2048/(1<<i));
	c[i][0] = 1;
	for (int j = 1; j <= lim; j++)
		c[i][j] = c[i][j-1] * (n-j+1) %mod * inv[j] %mod;
}
long long powmod(long long a, long long n, long long mod)
{
	if (n == 0) return 1;
	if (n == 1) return a;
	if (n & 1) return a * powmod(a * a % mod, n/2, mod) % mod;
	return powmod(a * a % mod, n/2, mod);
}
int main()
{
	int cas = 0;
	init();
	while(scanf("%d", &n))
	{
		if (n == 0) break;
		for (int i = 1; i <= 2048; i <<= 1) cnt[i] = 0;
		for (int i = 0; i < n; i++) cnt[read()] ++;
		int tot = 0;
		for (int i = 0; (1 << i) <= 2048; i++){
			getcom(i, cnt[1<<i]);
			tot += cnt[1<<i];
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; (1 << i) <= 2048; i++){
			int w = 1 << i;
			for (int j = 2047-w; j >= 0; j--){
				if (dp[j] == 0) continue;
				for (int k = 1; k <= cnt[1<<i]; k++){
					if (j + k * w > 2047) break;
					dp[j+k*w] = (dp[j+k*w] + dp[j] * c[i][k] % mod) % mod;
				}
			}
		}
		int anst = 0;
		for (int i = 0; i < 2048; i++) anst = anst + dp[i], anst = anst >= mod? anst-mod: anst;
		int ans = (powmod(2, tot, mod) - anst + mod) % mod * powmod(2, n-tot, mod) % mod;
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}
