#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 100000;
int T;
int bef[20010], aft[20010], a[20010], equ[20010][2];
int pre[maxn+100], nex[maxn+100];
long long ans;
int n;
int lowbit(int x)
{
	return x & -x;
}
void update(int x, int val, int sum[])
{
	for (int i = x; i <= maxn; i += lowbit(i))
		sum[i] += val;
}
int query(int x, int sum[])
{
	int ans = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		ans += sum[i];
	return ans;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		memset(pre, 0, sizeof(pre));
		memset(nex, 0, sizeof(nex));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			bef[i] = query(a[i], pre);
			equ[i][0] = bef[i] - query(a[i]-1, pre);
			update(a[i], 1, pre);
		}
		for (int i = n; i >= 1; i--){
			aft[i] = query(a[i], nex);
			equ[i][1] = aft[i] - query(a[i]-1, nex);
			update(a[i], 1, nex);
		}
		ans = 0;
		for (int i = 1; i <= n; i++){
			ans += (long long) bef[i] * (n-i-aft[i]) + (long long) (i-1-bef[i]) * aft[i];
			ans += (long long) equ[i][0] * equ[i][1];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
