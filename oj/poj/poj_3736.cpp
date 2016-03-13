#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const double eps = 1e-8;
struct node{
	double x, y, s, r, d, t;
} a[120];
int n;
double hp, sum;
bool cmp(node a, node b)
{
	return a.t < b.t;
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf %lf %lf %lf", &a[i].x, &a[i].y, &a[i].s, &a[i].r, &a[i].d);
			a[i].t = sqrt((a[i].x - 100)*(a[i].x - 100) + a[i].y*a[i].y) - a[i].r;
			if (a[i].t < eps) a[i].t = 0;
			sum = sum + a[i].d;
		}
		scanf("%lf", &hp);
		if (hp - sum > eps){
			puts("Safe!");
			continue;
		}
		sort(a, a+n, cmp);
		int pos = 0;
		double tim = 100;
		while(hp > eps){
			if (a[pos].t - tim > eps) break;
			else{
				tim = tim + a[pos].s;
				hp = hp - a[pos].d;
				pos++;
			}
		}
		if (hp > eps) puts("Safe!");
		else puts("Danger!");	
	}
	return 0;
}
