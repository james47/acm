#include<cstdio>
#include<cstring>
using namespace std;

const int mo = 200000007;
long long pow_mod(long long a, int b, int mo)
{
	if (b == 0) return 1;
	if (b == 1) return a % mo;
	long long tmp = pow_mod(a * a % mo, b / 2, mo);
	if (b & 1) return tmp * a % mo;
	else return tmp;
}
int T, n, m;
long long c[30][30], f[30];
int main()
{
	memset(c, 0, sizeof(c));
	c[0][0] = 1;
	for (int i = 0; i <= 20; i++)
		for (int j = 0; j <= i; j++){
			if (j == 0 || j == i) c[i][j] = 1;
			else c[i][j] = c[i-1][j-1] + c[i-1][j];
		}
	scanf("%d", &T);
	int cas = 0;
	while (T--)
	{
		scanf("%d %d", &n, &m);
		long long ans = 0;
		memset(f, 0, sizeof(f));
		if (n < m) ans = pow_mod(m, n, mo);
		else{
			for (int i = 1; i < m; i++){
				f[i] = pow_mod(i, n, mo);
				for (int j = 1; j < i; j++){
					f[i] -= c[i][j] * f[j] % mo;
					f[i] = (f[i] % mo + mo) % mo;
				}
				ans += f[i] * c[m][i];
				ans %= mo;
			}
		}
		cas++;
		printf("Case %d: %lld\n", cas, ans);
	}
	return 0;
}
