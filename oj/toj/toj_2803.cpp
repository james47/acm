#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const double eps = 1e-8;
int n;
double a, b, c, d, x1, x2;
int main()
{
	scanf("%d", &n);
	while(n--)
	{
		scanf("%lf %lf %lf", &a, &b, &c);
		d = b * b - a * c * 4;
		if (d < -eps){
			printf("No solution!\n");
			continue;
		}
		bool single = false;
		if (d < eps) single = true;
		d = sqrt(d);
		x1 = (-b - d) / a / 2;
		x2 = (-b + d) / a / 2;
		if (single) printf("%.3lf\n", x1);
		else printf("%.3lf %.3lf\n", x1, x2);
	}
	return 0;
}
