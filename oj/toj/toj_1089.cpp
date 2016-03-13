#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
ll pow_mod(ll a, ll n, ll mo)
{
	if (n == 0) return 1;
	if (n == 1) return a % mo;
	if (n & 1) return a * pow_mod(a * a % mo, n/2, mo) % mo;
	else return pow_mod(a * a % mo, n/2, mo);
}
int f(int x)
{
	int ret = (pow_mod(2, 2*x+1, 29) - 1 + 29) % 29;
	ret = ret * (pow_mod(3, x+1, 29) - 1 + 29) % 29 * pow_mod(2, 27, 29) * (pow_mod(167, x+1, 29) -1 + 29) % 29 * pow_mod(166, 27, 29) % 29;
	return ret;
}
int x;
int main()
{
	while(scanf("%d", &x), x)
	{
		printf("%d\n", f(x));
	}
	return 0;
}
