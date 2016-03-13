#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char c[10];
int n, q;
int sum[1010][1010];
int lowbit(int x)
{
	return x & -x;
}
void update(int x, int y, int val)
{
	for (int i = x; i <= n; i += lowbit(i))
		for (int j = y; j <= n; j += lowbit(j))
			sum[i][j] += val;
}
int query(int x, int y)
{
	int ans = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		for (int j = y; j > 0; j -= lowbit(j))
			ans += sum[i][j];
	return ans;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset(sum, 0, sizeof(sum));
		scanf("%d %d", &n, &q);
		int x1, x2, y1, y2;
		for (int i = 1; i <= q; i++){
			scanf("%s", c);
			if (c[0] == 'C'){
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				update(x1, y1, 1);
				update(x2+1, y1, 1);
				update(x1, y2+1, 1);
				update(x2+1, y2+1, 1);
			}
			else{
				scanf("%d %d", &x1, &y1);
				printf("%d\n", query(x1, y1)&1);
			}
		}
		if (T) printf("\n");
	}
	return 0;
}
