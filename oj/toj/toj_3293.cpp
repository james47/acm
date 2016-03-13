#include<cstdio>

const int mo = 200907;
int T, k;
long long a, b, c, ans;

long long pow_mod(long long a, long long n, long long mo)
{
	if (n == 0) return 1;
	if (n == 1) return a % mo;
	long long tmp = pow_mod(a, n/2, mo);
	tmp = tmp * tmp % mo;
	if (n & 1) return tmp * a % mo;
	return tmp;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld %lld %lld %d", &a, &b, &c, &k);
		if (b - a == c - b){
			long long del = (b - a) % mo;
			ans = (a % mo + (k-1) * del) % mo;
		}
		else{
			//double q = (double)b / (double)a;
			long long q = b / a;
			a %= mo;
			ans = a * pow_mod(q, k-1, mo) % mo; 
		}
		printf("%lld\n", ans);
	}
	return 0;
}
