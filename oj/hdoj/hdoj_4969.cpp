#include<cstdio>
#include<cmath>
using namespace std;

const double eps = 1e-8;
int T;
double v1, v2, r, d;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lf%lf%lf%lf", &v1, &v2, &r, &d);
		if (r*v2*asin(v1/v2)/v1 > d) puts("Why give up treatment");
		else puts("Wake up to code");
	}
	return 0;
}
