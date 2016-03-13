#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const double eps = 1e-6;
struct point{
	double x, y;
} a[2][20];
int n, nowl, nexl, now;
bool cmp(point a, point b)
{
	if (a.x < b.x) return true;
	return false;
}
point cal(point a, point b)
{
	point q;
	q.x = (a.x + b.x) / 2.0;
	q.y = (a.y + b.y) / 2.0;
	double k = (b.y - a.y) / (b.x - a.x);
	double dab = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	double dcq = sqrt(2.0 * 2.0 - (dab/2.0) * (dab/2.0));
	double theta1 = acos((b.x - a.x)/dab);
	double theta2 = acos((dab/4.0));
	point cir;
	double theta;
	if (a.y + eps <= b.y)
	{
		theta = theta1 + theta2;
	}
	else
	{
		theta = theta2 - theta1;
	}
	cir.x = a.x + cos(theta) * 2.0;
	cir.y = a.y + sin(theta) * 2.0;
//	printf("%.4lf %.4lf\n", cir.x, cir.y);
	return cir;
}
int main()
{
	int T, cas = 0;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		cas ++;
//	while(scanf("%d", &n) && n)
//	{
		double x, y = 1.0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf", &x);	
			a[0][i].x = x;
			a[0][i].y = y;
		}
		sort(a[0],a[0]+n,cmp);
		now = 0;
		nowl = n; nexl = 0;
		while(nowl != 1)
		{
			for (int i = 0; i < nowl - 1; i++)
			{
				point cir = cal(a[now][i], a[now][i+1]);
				a[now^1][nexl].x = cir.x;
				a[now^1][nexl].y = cir.y;
				nexl ++;
			}
			now ^= 1;
			nowl = nexl;
			nexl = 0;
		}
		printf("%d: ", cas);
		printf("%.4f %.4f\n", a[now][0].x, a[now][0].y);
//	}
	}
	return 0;
}
