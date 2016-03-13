#include<cstdio>
using namespace std;

const int maxn = (int)1e5+10;
struct node{
	int l, r;
	double h;
	node(){}
	node(int ll, int rr, double hh):l(ll), r(rr), h(hh){}
} stack[maxn];
int T, n;
int a[maxn], sum[maxn];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		sum[0] = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d", a+i);
			sum[i] = sum[i-1] + a[i];
		}
		int top = 0;
		for (int i = 1; i <= n; i++){
			node now = node(i, i, sum[i]-sum[i-1]);
			while(top > 0 && now.h < stack[top-1].h){ 
				top --;
				now.l = stack[top].l;
				now.h = (double)(sum[now.r] - sum[now.l-1])/(now.r - now.l + 1);
			}
			stack[top++] = now;
		}
		double ans = 0;
		for (int i = 0; i < top; i++){
			int ll = stack[i].l, rr = stack[i].r;
			int len = rr - ll + 1;
			double hh = stack[i].h;
			int tot = sum[rr] - sum[ll-1];
			ans += hh * hh * len - 2.0 * tot * hh + tot;
		}
		printf("%.6lf\n", ans);
	}
	return 0;
}
