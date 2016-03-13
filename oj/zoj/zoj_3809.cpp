#include<cstdio>
#include<cstring>
using namespace std;

int T, n, h[3000];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", h+i);
		int ans = 0;
		for (int i = 1; i < n-1; i++)
			if (h[i-1] < h[i] && h[i] > h[i+1]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
