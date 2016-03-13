#include<cstdio>
#include<cstring>
using namespace std;

long long h, a, b, k;
int main()
{
	int cas = 0;
	while(scanf("%lld %lld %lld %lld", &h, &a, &b, &k))
	{
		if (h+a+b+k <= 0) break;
		printf("Case #%d: ", ++cas);
		bool yes = false;
		if (h <= a) yes = true;
		if (k*a - (k-1)*b >= h) yes = true;
		if (k*a - (k+1)*b > 0) yes = true;
		if (yes) puts("YES");
		else puts("NO");
	}
	return 0;
}
