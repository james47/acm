#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T, n, x, y1, y2;
int a[10010];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%d %d %d", &x, &y1, &y2);
			a[y1] ++;
			a[y2+1] --;
		}
		int cnt = 0, ans = 0;
		for (int i = 0; i <= 10000; i++){
			cnt = cnt + a[i];
			if (cnt > ans) ans = cnt;
		}
		printf("%d\n", ans);
	}
	return 0;
}
