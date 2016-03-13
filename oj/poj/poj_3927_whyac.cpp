#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

struct node{
	long long l, r;
} a[100100];
bool cmp(node a, node b)
{
	return a.r + a.l <= b.r + b.l; 
}
int n;
int main()
{
	while(scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++){
			scanf("%lld%lld", &a[i].l, &a[i].r);
			a[i].l *= 2ll;
			a[i].r *= 2ll;
		}
		sort(a, a + n, cmp);
		bool flag = true;
		long long pre = 0;
		for (int i = 0; i < n; i++){
			long long tmp = (a[i].l + a[i].r)/2ll;
			if (pre >= tmp){
				flag = false;
				break;
			}
			pre = 1ll + max(pre, a[i].l) + (a[i].r - a[i].l)/2ll;
		}
		if (flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
