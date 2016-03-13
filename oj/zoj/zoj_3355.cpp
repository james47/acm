#include<cstdio>
#include<cstring>
using namespace std;

int T;
long long a, aa, b, bb, c, cc;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld.%lld %lld.%lld %lld.%lld", &a, &aa, &b, &bb, &c, &cc);
		a = a * 100 + aa;
		b = b * 100 + bb;
		c = c * 100 + cc;
		if (100ll * (a*b + b*c + a*c) < a*b*c)
			puts("Aha");
		else puts("No way");
	}
	return 0;
}
