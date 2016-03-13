#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 9;
const int maxn = 1e5;
int n, m;
LL x, y;
int a[maxn + 10];
LL rev[maxn + 10];
int extgcd(int a, int b, LL &x, LL &y)
{
	if (b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int gcd = extgcd(b, a % b, x, y);
	LL t = x; x = y; y = t - (a/b) * y;
	return gcd;
}
int main()
{
	for (int i = 0; i <= maxn; i++){
		extgcd(i, mod, x, y);
		if (x < 0) x += mod; //x = (x + mod) % mod;
		rev[i] = x; 
	}
	while(scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int l = a[0], r = a[0];
		for (int i = 1; i < n; i++){
			int nl, nr;
			if (a[i] <= l) nl = l - a[i];
			else if (a[i] <= r) nl = (a[i] + l) % 2;
			else nl = a[i] - r;
			if (r + a[i] <= m) nr = r + a[i];
			else if (l + a[i] <= m) nr = m - ((m - l + a[i]) % 2);
			else nr = m - (a[i] - (m - l)); 
			l = nl, r = nr;
		}
		int t = 0, sum = 0, tmp = 1;
		if (l == 0) sum ++;
		while (t < r){
			t++;
			tmp = (long long)(tmp) * (m-t+1) % mod * rev[t] % mod;
			if (l <= t && t <= r && !((t+l)&1)){
				sum += tmp;
				sum %= mod;
				//if (sum < 0) sum += mod;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
