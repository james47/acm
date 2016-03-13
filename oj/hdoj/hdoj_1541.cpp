#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 40000;
int n, sum[40000], ans[20000];
int lowbit(int x)
{
	return x&-x;
}
void update(int x)
{
	for (int i = x; i <= maxn; i += lowbit(i))
		sum[i] ++;
}
int query(int x)
{
	int ans = 0;
	for (int i = x; i >= 1; i -= lowbit(i)){
		ans += sum[i];
	}
	return ans;
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		memset(sum, 0, sizeof(sum));
		memset(ans, 0, sizeof(ans));
		int x, y;
		for (int i = 0; i < n; i++){
			scanf("%d %d", &x, &y);
			x++;
			ans[query(x)] ++;
			update(x);
		}
		for (int i = 0; i < n; i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}
