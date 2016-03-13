#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 50010;
typedef long long LL;
int T;
int lowbit(int x)
{
	return x & -x;
}
void update(int x, LL val)
{
	for (int i = x; i <= maxn; i += lowbit(i))
		sum[i] = sum[i] + val;
}
LL query(int x)
{
	LL ret = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		ret = ret + sum[i];
	return ret;
}
LL find(LL t, LL &s)
{
}
int main()
{
	scanf("%d", &T);
	int cas = 0;
	while(T--)
	{
		scanf("%d %d", &n, &m);
		printf("Case #%d:\n", ++ cas);
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++) update(i, 1);
		char tp;
		LL b, e, l, r, sum1, sum2;
		for (int i = 0; i < m; i++){
			scanf("%c%lld%lld", &tp, &b, &e);
			if (tp == 'D'){
				l = find(b, sum1);
				r = find(e, sum2);
				if (sum1 
			}
			else{
			}
		}
	}
	return 0;
}
