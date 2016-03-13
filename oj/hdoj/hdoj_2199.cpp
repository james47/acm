#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const double eps = 1e-8;
double cal(double x)
{
	double val = 6.0;
	val = val + 8.0*x*x*x*x + 7.0*x*x*x + 2.0*x*x + 3.0*x;
	return val;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		double y;
		scanf("%lf", &y);
		if (cal(0.0) > y || cal(100.0) < y)
		{
			printf("No solution!\n");
			continue;
		}
		double l = 0.0, r = 100.0, ans = -1.0, dis = 9.0 * 10e9;
		double mid;
		while (l + eps <= r && (dis > 1e-5))
		{
			mid = (l + r) / 2.0;
			double tmp = cal(mid);
			if (tmp < y + eps)
			{
				l = mid + eps;
				if (fabs(tmp - y) < dis)
				{
					ans = mid;
					dis = fabs(tmp - y);
				}
			}
			else
			{
				r = mid - eps;
				if (fabs(tmp - y) < dis)
				{
					ans = mid;
					dis = fabs(tmp - y);
				}
			}
		}
		printf("%.4lf\n", ans);
	}
	return 0;
}
