#include<cstdio>

long long x, k;
int main()
{
	int cas = 0;
	while(scanf("%lld %lld", &x, &k))
	{
		if (x == 0 && k == 0) break;
		for (long long i = 1; i < k; i++){
			if (x < i+1) break;
			x = x - x/(i+1);
		}
		printf("Case #%d: %lld\n", ++cas, x*k);
	}
	return 0;
}
