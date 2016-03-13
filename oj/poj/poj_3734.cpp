#include<cstdio>
using namespace std;

const int mo = 10007;
int T, n;
int pow_mod(int a, int n, int mo)
{
	if (n == 0) return 1;
	if (n == 1) return a % mo;
	int tmp = pow_mod(a, n/2, mo);
	tmp = tmp * tmp % mo;
	if (n & 1) return tmp * a % mo;
	else return tmp;
}
int cal(int n)
{
	return (pow_mod(2, n-1, mo) + pow_mod(2, 2*n-2, mo)) % mo;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		printf("%d\n", cal(n));
	}
	return 0;
}
