#include<cstdio>
#include<cstring>
using namespace std;

long long x;
int main()
{
	while(scanf("%lld", &x))
	{
		if (x == 0) break;
		long long ans, tmp = 1;
		while(tmp <= x){
			if (x % tmp == 0) ans = tmp;
			tmp = tmp * 10 + 1;
		}
		ans = x / ans;
		printf("%lld\n", ans);
	}
	return 0;
}
