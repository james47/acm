#include<cstdio>
#include<cmath>
using namespace std;

const double pi = acos(-1.0);
double s, v, h, r, r2;
int main()
{
	while(scanf("%lf", &s) != EOF)
	{
		r2 = s/pi/4.0;
		r = sqrt(r2);
		h = sqrt(s*s/r2/pi/pi - s*2/pi);
		v = pi * r2 * h / 3.0;
		printf("%.2lf\n%.2lf\n%.2lf\n", v, h, r);
	}
	return 0;
}
