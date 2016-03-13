#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;
int n;
LL x, y;
LL v[1010];
LL sum[1010];
LL cal(int index, LL pos)
{
	if (index == 0) return (pos+1ll)*pos/2ll;
	if (pos % v[index-1] == 0) return sum[index-1] * (pos / v[index-1]);
	else return sum[index-1] * (pos/v[index-1] + 1) - cal(index-1, v[index-1] - pos%v[index-1]);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i ++){
			scanf("%lld", v+i);
			sum[i] = cal(i, v[i]);
		}
		scanf("%lld %lld", &x, &y);
		printf("%lld\n", cal(n-1,y) - cal(n-1, x-1));
	}
	return 0;
}
