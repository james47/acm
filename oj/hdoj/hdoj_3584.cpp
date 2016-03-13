#include<cstdio>
#include<cstring>
using namespace std;

int n, m;
int sum[110][110][110];
int lowbit(int x)
{
	return x & -x;
}
void update(int x, int y, int z, int val)
{
	for (int i = x; i <= n; i += lowbit(i))
		for (int j = y; j <= n; j += lowbit(j))
			for (int k = z; k <= n; k += lowbit(k))
				sum[i][j][k] += val;
}
int query(int x, int y, int z)
{
	int ans = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		for (int j = y; j > 0; j -= lowbit(j))
			for (int k = z; k > 0; k -= lowbit(k))
				ans += sum[i][j][k];
	return ans;
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		memset(sum, 0, sizeof(sum));
		int q, x1, x2, y1, y2, z1, z2;
		for (int i = 0; i < m; i++){
			scanf("%d", &q);
			if (q){
				scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
				update(x1, y1, z1, 1);
				update(x1, y1, z2+1, 1);
				update(x1, y2+1, z1, 1);
				update(x2+1, y1, z1, 1);
				update(x2+1, y2+1, z1, 1);
				update(x2+1, y1, z2+1, 1);
				update(x1, y2+1, z2+1, 1);
				update(x2+1, y2+1, z2+1, 1);
			}
			else{
				scanf("%d %d %d", &x1, &y1, &z1);
				printf("%d\n", query(x1, y1, z1)&1);
			}
		}
	}
	return 0;
}
