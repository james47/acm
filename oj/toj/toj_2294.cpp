#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define debug 0
#define bug 0
long long a, b;
long long f[40], g[40];
int d[40];
long long G(int x)
{
	if (x == 1) return 1;
	return G(x-1) + f[x-2] * 9;
}
void init()
{
	f[0] = 0;
	long long exp = 1;
	for (int i = 1; i < 40; i++){
		f[i] = f[i-1] * 10 + exp;
		exp = exp * 10;
	}
	for (int i = 1; i < 40; i++)
		g[i] = G(i);
}
long long cal(long long x)
{
	if (debug) printf("%lld\n", x);
	if (x == -1) return 0;
	if (x == 0) return 1;
	int len = 0;
	while(x){
		d[len++] = x % 10;
		x /= 10;
	}
	long long ret = g[len] + f[len-1] * (d[len-1]-1);
	if (debug) printf("%lld\n", ret);
	long long exp = 1;
	for (int i = 0; i < len-2; i++)
		exp = exp * 10;
	for (int i = len-2; i >= 0; i--){
		if (d[i]) ret = ret + exp;
		else{
			long long tmp = 0;
			for (int j = i-1; j >= 0; j --)
				tmp = tmp * 10 + d[j];
			ret = ret + tmp + 1;
		}
		exp = exp / 10;
		ret = ret + f[i] * d[i];
	}
	if (debug) printf("%lld\n", ret);
	return ret;
}
int main()
{
	init();
	while(scanf("%lld %lld", &a, &b))
	{
		if (a < 0 || b < 0) break;
		if (bug) printf("%lld %lld\n", cal(b), cal(a-1));
		printf("%lld\n", cal(b) - cal(a-1));
	}
	return 0;
}
