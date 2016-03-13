#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int mod = 1e9 + 9;
const int maxn = 1e5;
int n, m, x, y;
int a[maxn + 10], rev[maxn + 10];
int extgcd(int a, int b, int &x, int &y)
{
	if (b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int gcd = extgcd(b, a % b, y, x);
	y -= (a/b)*x;
	return gcd;
}
int main()
{
	for (int i = 0; i <= maxn; i++){
		extgcd(mod, i, x, y);
		if (x < 0) x += mod;
		rev[i] = x; 
	}
	for (int i = 0; i <= 10; i++)  printf("%d\n", rev[i]);
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
		//printf("%d %d\n", l, r);
		int t = 0, sum = 0, tmp = 1;
		if (l == 0) sum ++;
		while (t < r){
			t++;
			tmp = (tmp * (m-t+1) * rev[t]) % mod;
			printf("%d\n", tmp);
			if (l <= t && t <= r && !((t+l)&1)){
				sum += tmp;
				if (sum > mod) sum -= mod;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
