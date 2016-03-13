#include<cstdio>
#include<cstring>
using namespace std;

int n, b[100100];
int lowbit(int x)
{
	return x & -x;
}
void update(int x, int k)
{
	for (int i = x; i <= n; i += lowbit(i))
		b[i] += k;
}
int query(int x)
{
	int ans = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		ans += b[i];
	return ans;
}
int main()
{
	while(scanf("%d", &n) && n)
	{
		memset(b, 0, sizeof(b));
		int a, b;
		for (int i = 0; i < n; i++){
			scanf("%d %d", &a, &b);
			update(a, 1);
			update(b+1, -1);
		}
		for (int i = 1; i < n; i++)
			printf("%d ", query(i));
		printf("%d\n", query(n));
	}
	return 0;
}
