#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<ctime>
#include<string>
using namespace std;

struct node{
	int e, k;
}a[101000];
int n, sum[101000];
bool cmp(node a, node b)
{
	return a.e * b.k < b.e * a.k;
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i].e);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i].k);
		sort(a, a+n, cmp);
		sum[0] = 0;
		for (int i = 0; i < n; i++)
			sum[i] = sum[i-1] + a[i].e;
		long long ans = 0;
		for (int i = 0; i < n; i++)
			ans += (long long)(sum[i]) * a[i].k;
		printf("%I64d\n", ans);
		//printf("%lld\n", ans);
	}
	return 0;
}
