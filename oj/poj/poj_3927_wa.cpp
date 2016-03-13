#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const double eps = 1e-6;
struct node{
	int l, r;
	double m, s;
} a[100100];
bool cmp(node a, node b)
{
	return a.m < b.m;
}
double max(double a, double b)
{
	if (a > b) return a;
	else return b;
}
int n;
int main()
{
	while(scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++){
			scanf("%d%d", &a[i].l, &a[i].r);
			a[i].m = (double(a[i].l) + a[i].r) / 2.0;
			a[i].s = (double(a[i].r) - a[i].l) / 2.0;
		}
		sort(a, a + n, cmp);
		bool flag = true;
		double pre = 0.0;
		for (int i = 0; i < n; i++){
			if (pre > a[i].m - eps){
				flag = false;
				break;
			}
			pre = max(pre, double(a[i].l)) + a[i].s;
		}
		if (flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
