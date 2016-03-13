#include<cstdio>
#include<cstring>
using namespace std;

int n, m, T;
long long a[100100];
long long ans;
int lowbit(int x)
{
	return x & -x;
}
void update(int x, long long val)
{
	for (int i = x; i <= n; i += lowbit(i))
		a[i] += val;
}
long long query(int x)
{
	long long ans = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		ans += a[i];
	return ans;
}
int main()
{
	int cas = 0;
	scanf("%d", &T);
	while(T--)
	{
		memset(a, 0, sizeof(a));
		scanf("%d %d", &n, &m);
		long long x;
		for (int i = 1; i <= n; i++){
			scanf("%lld", &x);
			update(i, x);
			update(i+1, -x);
		}
		ans = 0;
		for (int i = 1; i <= n; i++){
			int tmp = query(i);
			if (tmp > 0){
				ans += tmp;
				update(i, -tmp);
				update(i+m, tmp);
			}
		}
		cas++;
		printf("Case #%d: %lld\n", cas, ans);
	}
	return 0;
}
