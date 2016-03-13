#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int mod = 998244353;
int n, cnt[2050];
long long dp[2050];
int inv[2050], c[15][2050];

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
	for (int i = 2; i <= 2048; i++) inv[i] = (long long)inv[mod%i] * (mod - mod/i) % mod;
}
void getcom(int i, int n)
{
	int lim = min(n, 2048/(1<<i));
	c[i][0] = 1;
	long long ans = 1;
	for (int j = 1; j <= lim; j++){
		ans = ans * (n-j+1) %mod * inv[j] %mod;
		c[i][j] = ans;
	}
}
long long powmod(long long a, long long n, long long mod)
{
	if (n == 0) return 1;
	if (n == 1) return a;
	if (n & 1) return a * powmod(a * a % mod, n/2, mod) % mod;
	return powmod(a * a % mod, n/2, mod);
}
void zip(int x)
{
	for (int i = 0; i+x <= 2048; i += (x<<1))
		dp[i] = (dp[i] + dp[i+x]) % mod;
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
		for (int i = 0; (1<<i) <= 2048; i++){
			int w = 1 << i;
			for (int j = 2048; j >= 0; j -= w){
				if (dp[j] == 0) continue;
				for (int k = 1; k <= cnt[w]; k++){
					if (j + k * w > 2047) break;
					dp[j+k*w] = (dp[j+k*w] + dp[j] * c[i][k] % mod) % mod;
				}
			}
			zip(w);
		}
		int anst = dp[0] % mod;
		int ans = (powmod(2, tot, mod) - anst + mod) % mod * powmod(2, n-tot, mod) % mod;
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}
